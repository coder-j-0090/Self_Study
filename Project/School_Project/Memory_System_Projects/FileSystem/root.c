/**************************************************************
* Class::  CSC-415-03 Fall 2024
* Name:: Justin Ho, Junyoung Kim, Ryan Flannery. Bilguun Bayasgalan
* Student IDs:: 922266680, 920303420, 921824732, 922564900
* GitHub-Name:: justinh128
* Group-Name:: Innov8
* Project:: File System
*
* File:: root.c
*
* Description:: Root Directory initialization and write functions.
*
**************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>
#include "root.h"
#include "vcb.h"
#include "free_space.h"

DE *rootDir = NULL;
DE *curDir = NULL;
 
// Method to initialize the root directory
void RootDirecInit(struct RootDirectory *rootDirStruct, uint32_t rootBlockNum) 
{

    // Allocate memory for the global rootDir
    rootDir = malloc(sizeof(struct RootDirectory));
    if (rootDir == NULL) {
        printf("Memory allocation failed for rootDir!\n");
        exit(EXIT_FAILURE);
    }

    rootDirStruct->entry_count = 2;    // Starting with "." and ".."
    rootDirStruct->size = MAX_ENTRIES * sizeof(DE); // Total size of directory

    //Initialize ".", which represent the current directory.
    strncpy(rootDirStruct->entries[0].name, ".", MAX_NAME_LEN); // Copy "." as the directory name
    rootDirStruct->entries[0].isDir = true;                     // "." is a directory
    rootDirStruct->entries[0].location = rootBlockNum;          // Block number assigned to root
    rootDirStruct->entries[0].size = rootDirStruct->size;             // Set size of this directory
    rootDirStruct->entries[0].creation_time = time(NULL);       // Set creation time to current time
    rootDirStruct->entries[0].modification_time = rootDirStruct->entries[0].creation_time; // Sync modification time
    rootDirStruct->entries[0].access_time = rootDirStruct->entries[0].creation_time;       // Sync access time

    //Initialize ".", which represent the parent directory.
    strncpy(rootDirStruct->entries[1].name, "..", MAX_NAME_LEN); // Copy ".." as the directory name
    rootDirStruct->entries[1].isDir = true;                      // ".." is a directory
    rootDirStruct->entries[1].location = rootBlockNum;           // Same block number as "." since it’s root
    rootDirStruct->entries[1].size = rootDirStruct->size;              // Size of this directory
    rootDirStruct->entries[1].creation_time = rootDirStruct->entries[0].creation_time; // Sync with "."
    rootDirStruct->entries[1].modification_time = rootDirStruct->entries[0].modification_time; // Sync with "."
    rootDirStruct->entries[1].access_time = rootDirStruct->entries[0].access_time;      // Sync with "."

    // Initialize all remaining entries in the directory array to default values
    for (int i = 2; i < MAX_ENTRIES; i++) 
    {
        rootDirStruct->entries[i].name[0] = '\0';    
        rootDirStruct->entries[i].isDir = false;    
        rootDirStruct->entries[i].location = 0;    
        rootDirStruct->entries[i].size = 0;         
        rootDirStruct->entries[i].permissions = 0;   
        rootDirStruct->entries[i].creation_time = 0;  
        rootDirStruct->entries[i].modification_time = 0;
        rootDirStruct->entries[i].access_time = 0;
    }

    // Copy initialized directory into rootDir global pointer
    memcpy(rootDir, rootDirStruct, sizeof(struct RootDirectory));

    // Set the current directory to rootDirStruct
    curDir = rootDir;

    printf("Root directory initialized. Current directory set to root.\n");
}

// Method to write the root directory to volume file
int writeRootToVol(const char *volumeFile, struct RootDirectory *rootDirStruct) 
{
    // Open file in read/write binary mode to read and write
    FILE *volumeFileName = fopen(volumeFile, "rb+");
    
    if (volumeFileName != NULL) {
        printf("Error: Failed to open volume file %s.\n", volumeFile);
	return -1;
    }
    // Set the file pointer to the correct position
    if (fseek(volumeFileName, BLOCK_SIZE, SEEK_SET) != 0) {
        printf("Error: Failed to seek to the root directory location.\n");
        fclose(volumeFileName);
        return -1; // Error seeking
    }

    // Write the root directory structure to the volume file
    size_t written = fwrite(rootDirStruct, sizeof(struct RootDirectory), 1, volumeFileName);
    if (written != 1) {
        printf("Error: Failed to write root directory to disk.\n");
        fclose(volumeFileName);
        return -1; // Error writing
    }

    // Close the file to save changes
    fclose(volumeFileName);
    printf("Root directory written to volume successfully.\n");
    return 0; // Success
}
