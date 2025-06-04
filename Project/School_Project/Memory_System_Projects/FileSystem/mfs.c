/**************************************************************
* Class::  CSC-415-03 Fall 2024
* Name:: Justin Ho, Junyoung Kim, Ryan Flannery. Bilguun Bayasgalan
* Student IDs:: 922266680, 920303420, 921824732, 922564900
* GitHub-Name:: justinh128
* Group-Name:: Innov8
* Project:: File System
*
* File:: mfs.c
*
* Description:: Core functions for managing directories, file
  operations, and interactions. 
*
**************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include "mfs.h"
#include "root.h"
#include "vcb.h"
#include "fsLow.h"
#include "free_space.h"

bool isUsed(DE *entry) {

    // Validate input to ensure entry is not NULL
    if (entry == NULL) {
        return false;
    }

    // Check if the entry has a valid name (non-empty)
    if (strlen(entry->name) == 0) {
        return false;
    }

    // Return true if the name exists and is not empty
    return true;
}

int FindInDir(DE *parent, char *name) {

    // Validate parent directory and name must not be NULL
    if (parent == NULL || name == NULL) {
        return -2;
    }

    // Calculate the number of entries in the parent directory
    int numEntries = parent[0].size / sizeof(DE);
 
    // Iterate through the directory entries to find a match
    for (int i = 0; i < numEntries; i++) {
        if (isUsed(&parent[i])) {

            // Compare the current entry's name with the target name
            if (strcmp(parent[i].name, name) == 0) {
                return i;
            }
        }
    }

    // If no matching entry is found, return -1
    return -1;
}

DE *LoadDir(DE *dirEntry) {
    if (!dirEntry || !dirEntry->isDir) {
        printf("Error: Invalid directory entry or not a directory.\n");
        return NULL;
    }

    // Allocate memory for the directory entries
    DE *loadedDir = (DE *)malloc(MAX_ENTRIES * sizeof(DE));
    if (!loadedDir) {
        printf("Error: Memory allocation failed for LoadDir.\n");
        return NULL;
    }

    int blocksRead = LBAread(loadedDir, 1, dirEntry->location); 
    if (blocksRead != 1) {
        printf("Error: Failed to read directory from location %u.\n", dirEntry->location);
        free(loadedDir);
        return NULL;
    }

    // Print the loaded directory entries for debugging
    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (loadedDir[i].name[0] != '\0') { // Check if entry is valid
            printf("Loaded entry: %s (isDir: %d, location: %u)\n", 
                   loadedDir[i].name, loadedDir[i].isDir, loadedDir[i].location);
        }
    }

    return loadedDir;
}

void FreeDir(DE *dirEntry) {
    if (!dirEntry) {
        printf("Warning: Attempted to free a NULL directory.\n");
        return;
    }

    free(dirEntry);
    printf("Directory memory freed successfully.\n");
}

int ParsePath(const char *path, DE **retParent, int *index, char **lastElementName) {

    // Validate the input path
    if (path == NULL || strlen(path) == 0) {

	// Ensure the caller does not pass a null pointer to avoid a segmentation fault
        printf("Error: Invalid path (NULL or empty).\n");
        return -1; 
    }

    if (strlen(path) == 0) {

        // Prevents empty strings from being processed as valid paths
        return -1;
    }

    // Create a mutable copy of the path
    char pathCopy[MAX_PATH];
    strncpy(pathCopy, path, MAX_PATH - 1);
    pathCopy[MAX_PATH - 1] = '\0'; // Ensure null-termination

    // Determine starting directory: rootDir (for absolute)  or curDir (for relative)
    DE *start = (path[0] == '/') ? rootDir : curDir;
    if (!start) {
        printf("Error: Starting directory not initialized.\n");
        return -1;
    }

    // Initially set the parent to the starting directory
    DE *parent = start;
    char *token1;        // Holds the current path element
    char *token2;        // Holds the next path element (if any)
    char *savePtr;       // Used by strtok_r to maintain state across calls

    // Tokenize the path by splitting it on '/'
    token1 = strtok_r(pathCopy, "/", &savePtr);
    
    // If the path is just "/", it refers to the root directory
    if (!token1) {
        *retParent = parent;     // Set parent to rootDir
        *lastElementName = NULL;  // No element name for root path
        *index = 0;               // Index 0 for root directory
        return 0;
    }

    // Get the next token to determine if token1 is the last element
    token2 = strtok_r(NULL, "/", &savePtr);

    // If token2 is NULL, token1 is the last element of the path.
    int idx = FindInDir(parent, token1);
    if (!token2) {

        // If token1 is the last element in the path:
        *retParent = parent;
        *index = idx;
        *lastElementName = token1;
        return 0;
    }

    // If token1 is not the last element, ensure it exists and is a directory
    if (idx == -1) {
        return -1;
    }

    // Ensure token1 is a directory if it is not the last element
    if (parent[idx].isDir != 1) {
        return -1;
    }

    // Load the directory entry for token1 to continue parsing
    DE *newParent = LoadDir(&parent[idx]);

    // Free the current parent directory to avoid memory leaks
    FreeDir(parent);

    // Update the parent directory for the next iteration
    parent = newParent;
    token1 = token2;

    // Loop through remaining tokens in the path
    while (token1 != NULL) {
        token2 = strtok_r(NULL, "/", &savePtr);

        // Look for the current token (token1) in the parent directory
        idx = FindInDir(parent, token1);

        if (token2 == NULL) {
            *retParent = parent;
            *index = idx;
            *lastElementName = token1;
            return 0;
        }

        if (idx == -1) {
            return -1;
        }

        if (parent[idx].isDir != 1) {
            return -1;
        }

        // Load the directory entry for token1 to continue parsing
        newParent = LoadDir(&parent[idx]);
        FreeDir(parent);

        // Update the parent directory for the next iteration.
        parent = newParent;
        token1 = token2;
    }

    // If we exit the loop without returning, the path was invalid.
    return -1;
}


char * fs_getcwd(char *pathname, size_t size) {
 
   if (pathname == NULL) {
        return NULL;
    }

    // Initialize empty path and ensure it is within size limits
    pathname[0] = '\0';

    DE *current = curDir;
    char tempPath[4096];
    tempPath[0] = '\0';

    // Traverse backward to build the path in reverse
    while (current != rootDir) {
        char entryName[MAX_NAME_LEN];
        strncpy(entryName, current->name, MAX_NAME_LEN);
        entryName[MAX_NAME_LEN - 1] = '\0';
        
	int written = snprintf(tempPath, sizeof(tempPath), "/%s%s", entryName, tempPath);
	if (written < 0 || (size_t)written >= sizeof(tempPath)) {
    		printf("Error: Path truncated in fs_getcwd.\n");
    		return NULL; // Handle the truncation error appropriately
	}
  
	// Move up to the parent directory.
	current = current->parent;
    }

    // Add the root directory if the path is empty.
    if (tempPath[0] == '\0') {
        strncpy(tempPath, "/", sizeof(tempPath));
    }

    // Copy the built path into the pathname buffer.
    strncpy(pathname, tempPath, size - 1);
    pathname[size - 1] = '\0';

    return pathname;
}

int fs_setcwd(char *pathname) {
  
    if (pathname == NULL) {
        return -1;
    }

    DE *newDir = NULL;
    char *lastElementName = NULL;
    int index = -1;

    // Parse the given path
    if (ParsePath(pathname, &newDir, &index, &lastElementName) != 0) {
        printf("Error: Path does not resolve to a valid directory.\n");
        return -2;
    }

    // Ensure the resolved entry is a directory
    if (!newDir[index].isDir) {
        printf("Error: Path does not point to a directory.\n");
        return -3;
    }

    // Update the current working directory
    curDir = &newDir[index];
    printf("Current working directory set to: %s\n", curDir->name);

    return 0;
}


int fs_isFile(const char *filename) {

    if (filename == NULL) {
        return -1;
    }

    DE *parent = NULL;
    char *lastElementName = NULL;
    int index = -1;

    // Parse the given path to resolve the file/directory
    if (ParsePath(filename, &parent, &index, &lastElementName) != 0) {
        printf("Error: Path does not resolve to a valid entry.\n");
        return -2;
    }

    // If the entry exists, check its type
    if (!parent[index].isDir) {
        return 1;
    } else {
        return 0;
    }
}
// Opens a directory for reading
fdDir * fs_opendir(const char *pathname) {
    // Check if path is valid
    if (pathname == NULL || strlen(pathname) == 0) {
        return NULL;
    }

    DE *parent = NULL;
    int index = -1;
    char *lastElementName = NULL;

    // Try to find the directory
    if (ParsePath((char *)pathname, &parent, &index, &lastElementName) != 0 || index < 0) {
        // Clean up if directory not found
        FreeDir(parent);
        return NULL;
    }

    // Make sure it's actually a directory
    if (!parent[index].isDir) {
        FreeDir(parent);
        return NULL;
    }

    // Get directory contents
    DE *dirEntries = LoadDir(&parent[index]);
    if (!dirEntries) {
        FreeDir(parent);
        return NULL;
    }

    // Create space for directory info
    fdDir *dirp = (fdDir *)malloc(sizeof(fdDir));
    if (!dirp) {
        FreeDir(dirEntries);
        FreeDir(parent);
        return NULL;
    }

    // Create space for each directory entry
    dirp->di = (struct fs_diriteminfo *)malloc(sizeof(struct fs_diriteminfo));
    if (dirp->di == NULL) {          
    FreeDir(dirEntries);
    FreeDir(parent);
    free(dirp);
    return NULL;
}

    // Set up directory info
    dirp->d_reclen = sizeof(fdDir);
    dirp->dirEntryPosition = 0;
    dirp->directory = dirEntries;
    dirp->numEntries = parent[index].size / sizeof(DE);
    // Check if directory has entries
    if (dirp->numEntries <= 0) {
        dirp->numEntries = 0;
    }

    FreeDir(parent);

    return dirp;
}
// fs_readdir function
struct fs_diriteminfo *fs_readdir(fdDir *dirp) {
    // Check if input is valid
    if (!dirp) {
        return NULL;
    }

    // Check if we're at the end
    if (dirp->dirEntryPosition >= dirp->numEntries) {
        return NULL;
    }


    // Look through entries
    while (dirp->dirEntryPosition < dirp->numEntries) {
        // Get current entry
        DE *currentEntry = &(dirp->directory[dirp->dirEntryPosition]);
        dirp->dirEntryPosition++;
        // If entry is valid
        if (isUsed(currentEntry)) {
            // Fill in entry info
            dirp->di->d_reclen = sizeof(struct fs_diriteminfo);
            dirp->di->fileType = currentEntry->isDir ? FT_DIRECTORY : FT_REGFILE;

            // Copy name safely
            strncpy(dirp->di->d_name, currentEntry->name, sizeof(dirp->di->d_name) - 1);
            dirp->di->d_name[sizeof(dirp->di->d_name) - 1] = '\0'; // Ensure null-termination

            return dirp->di;
        }
    }

    return NULL;
}

// int fs_isDir(const char *path) {
// 	mode_t *index_node = fs_lookup(path);
// 	if (NULL == index_node) {
// 		return 0; // Path does not exist
// 	}
// 	return index_node->type == DIR; // Assuming 'DIR' is defined as the type for directories
// }
int fs_isDir(const char *path) {
    if (path == NULL) {
        return 0;
    }

    DE *parent = NULL;
    int index = -1;
    char *lastElementName = NULL;

    // Use ParsePath to find the directory entry
    if (ParsePath((char *)path, &parent, &index, &lastElementName) != 0) {
        return 0;
    }

    // Check if the entry exists and is a directory
    if (parent == NULL || index < 0) {
	FreeDir(parent);
        return 0;
    }
    int isDir = parent[index].isDir;
    FreeDir(parent);
    return isDir;
}

int fs_add_entry(const char *parentPath, DE *newEntry) {
    if (parentPath == NULL || newEntry == NULL) {
        printf("Error: Invalid arguments to fs_add_entry.\n");
        return -1;
    }

    DE *parentDirEntries = NULL;
    int parentIndex = -1;
    char *lastElementName = NULL;

    // Parse the parent path to get the parent directory
    if (ParsePath((char *)parentPath, &parentDirEntries, &parentIndex, &lastElementName) != 0) {
        printf("Error: Failed to parse parent path '%s'.\n", parentPath);
        return -1;
    }

    // Ensure the parent directory exists
    if (parentIndex < 0 || !parentDirEntries[parentIndex].isDir) {
        printf("Error: Parent path '%s' is not a directory.\n", parentPath);
        FreeDir(parentDirEntries);
        return -1;
    }

    // Load the parent directory entries from disk
    DE *parentDir = LoadDir(&parentDirEntries[parentIndex]);
    if (parentDir == NULL) {
        printf("Error: Failed to load parent directory '%s'.\n", parentPath);
        FreeDir(parentDirEntries);
        return -1;
    }

    // Find an empty slot in the parent directory
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (parentDir[i].name[0] == '\0') {
            // Empty slot found
            break;
        }
    }

    if (i == MAX_ENTRIES) {
        printf("Error: Parent directory '%s' is full.\n", parentPath);
        FreeDir(parentDir);
        FreeDir(parentDirEntries);
        return -1;
    }

    // Add the new entry to the parent directory
    memcpy(&parentDir[i], newEntry, sizeof(DE));

    // Update the parent directory on disk
    int blocksWritten = LBAwrite(parentDir, 1, parentDirEntries[parentIndex].location);
    if (blocksWritten != 1) {
        printf("Error: Failed to write updated parent directory to disk.\n");
        FreeDir(parentDir);
        FreeDir(parentDirEntries);
        return -1;
    }

    // Optionally update the parent directory's metadata
    parentDirEntries[parentIndex].modification_time = time(NULL);

    // Write the updated parent directory entry back to disk
    blocksWritten = LBAwrite(&parentDirEntries[parentIndex], 1, parentDirEntries[parentIndex].location);
    if (blocksWritten != 1) {
        printf("Error: Failed to update parent directory entry on disk.\n");
        FreeDir(parentDir);
        FreeDir(parentDirEntries);
        return -1;
    }

    // Clean up
    FreeDir(parentDir);
    FreeDir(parentDirEntries);

    return 0; // Success
}


int fs_mkdir(const char *path, mode_t mode) {
	if (fs_isDir(path) || fs_isFile(path)) {
		return -1; // Directory or file already exists at path
	}
	char parent [MAX_PATH];
	strcpy(parent, path);
	dirname(parent);
	if (!fs_isDir(parent)) {
		return -1; 
	}
	
    	// Allocate a new directory entry
    	DE *newDir = (DE *)malloc(sizeof(DE));
    	if (!newDir) {
        	printf("Error: Memory allocation failed for new directory entry.\n");
        	return -1; // Allocation failed
    	}

    	// Initialize the new directory entry
    	strncpy(newDir->name, path, MAX_NAME_LEN);
    	newDir->name[MAX_NAME_LEN - 1] = '\0'; // Ensure null termination
    	newDir->isDir = true;                  // Mark as directory
    	newDir->location = allocateBlock(); // Allocate a block for the directory
    	newDir->size = 0;                      // Initial size is 0
    	newDir->permissions = mode;            // Set permissions
    	newDir->creation_time = time(NULL);    // Set creation time
    	newDir->modification_time = newDir->creation_time;
    	newDir->access_time = newDir->creation_time;

    	// Allocate a block for the new directory
    	newDir->location = allocateBlock();
    	if (newDir->location == 0) {
        	printf("Error: No free blocks available for new directory.\n");
        	free(newDir); // Cleanup on failure
        	return -1; // Block allocation failed
    	}
    	newDir->size = BLOCK_SIZE; // Set the size of the directory to one block

    	// Add the new directory entry to the parent directory
    	if (fs_add_entry(parent, newDir) != 0) {
        	printf("Error: Failed to add directory entry to parent directory '%s'.\n", parent);
        	free(newDir); // Free allocated memory on failure
        	return -1;
    	}

    	printf("Directory '%s' created successfully in parent '%s'.\n", path, parent);
    	return 0; // Success
}

int fs_closedir(fdDir *dir) {
    if (dir == NULL) {
        return -1;
    }
    
    if (dir->directory) {
        FreeDir(dir->directory);
    }
    if (dir->di) {
        free(dir->di);
    }
    free(dir);
    return 0;
}


int fs_stat(const char *path, struct fs_stat *buf) {

    if (path == NULL || buf == NULL) {
        return -1; // Invalid path or buffer
    }

    DE *parent = NULL; // Points to the parent directory of the target path
    int i = -1; // Index to the target directory entry within the parent directory
    char *lastElementName = NULL;

    // Parsing the path to find the given directory entry 
    // ParsePath will return the directory with the target and the index of it 
    int stat = ParsePath((char *)path, &parent, &i, &lastElementName);
    if (stat != 0 || i < 0){
        return -1; // The path doesn't exist 
    }

    DE *dir_entry = &parent[i];
    if (dir_entry == NULL){
        return -1; // Directory entry not found
    }

    // Populating the fs_stat struct in mfs.h with metadata from the directory entry
    buf->st_size = dir_entry->size; // Set the size from the directory entry
    buf->st_blksize = BLOCK_SIZE;   // 512 Byte sized block
    buf->st_blocks = (buf->st_size + BLOCK_SIZE - 1) / BLOCK_SIZE; 
    buf->st_createtime = dir_entry->creation_time;  // Creating created time from directory entry
    buf->st_modtime = dir_entry->modification_time; // Creating modification time from directory entry
    buf->st_accesstime = time(NULL); 

    // Success 
    return 0;
}
    
// Removes a file from a directory entry
int fs_delete(char *filename) {

    // Retreving the file information from fs_stat
    struct fs_stat fileStatus;
    int stat = fs_stat(filename, &fileStatus);
    if (stat != 0){
        printf("File not found.\n");
        return -1; // File must not exist
    }

    if(filename == NULL){
        return -1; // Not a valid filename
    }

    DE *parent = NULL; // Points to the parent directory of the target path
    int i = -1; // Index to the target directory entry within the parent directory
    char *lastElementName = NULL;

    int searchResult = ParsePath(filename, &parent, &i, &lastElementName);
    if (searchResult != 0 || i < 0){
        return -1; // The file was not found
    }

    DE *fileEntry = &parent[i];
    if(fileEntry == NULL){
        return -1; // file entry not valid
    }

    // Clearing the file in the directory to consider it as deleted
    memset(&parent[i], 0, sizeof(DE)); // clearing the entry to delete it
    printf("File %s deleted successfully", filename);

    // Success 
    return 0;

}

int fs_rmdir(const char *pathname) {

    struct fs_stat dirStatus;
    int status = fs_stat(pathname, &dirStatus);

    if(status != 0) {
        printf("Directory doesn't exist!\n");
        return -1;
    }




    // Success 
    printf("Directory removed!\n");
    return 0;
}
