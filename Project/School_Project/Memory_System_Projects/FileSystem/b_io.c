/**************************************************************
* Class::  CSC-415-0# Spring 2024
* Name::
* Student IDs::
* GitHub-Name::
* Group-Name::
* Project:: Basic File System
*
* File:: b_io.c
*
* Description:: Basic File System - Key File I/O Operations
*
**************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>			// for malloc
#include <string.h>			// for memcpy
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "b_io.h"
#include <stdint.h>
#include "fsLow.h"
#include "root.h"
#include "mfs.h"
#include "free_space.h"
#include "vcb.h"

#define MAXFCBS 20
#define B_CHUNK_SIZE 512

typedef struct b_fcb
	{
	/** TODO add al the information you need in the file control block **/
	char * buf;		//holds the open file buffer
	int index;		//holds the current position in the buffer
	int buflen;		//holds how many valid bytes are in the buffer
	uint64_t fileSize;      // Total size of the file
	uint32_t currentBlock;  // Current block being accessed
	uint32_t blockStart;    // Starting block of the file on disk
	uint32_t mode;          // File mode (read, write, append)
	uint32_t numBlocks; 
	int flags;              // File open flags
	fileInfo * fi;

	} b_fcb;
	
b_fcb fcbArray[MAXFCBS];

int startup = 0;	//Indicates that this has not been initialized

//Method to initialize our file system
void b_init ()
	{
	//init fcbArray to all free
	for (int i = 0; i < MAXFCBS; i++)
		{
		fcbArray[i].buf = NULL; //indicates a free fcbArray
		}
		
	startup = 1;
	}

//Method to get a free FCB element
b_io_fd b_getFCB ()
	{
	for (int i = 0; i < MAXFCBS; i++)
		{
		if (fcbArray[i].buf == NULL)
			{
			return i;		//Not thread safe (But do not worry about it for this assignment)
			}
		}
	return (-1);  //all in use
	}

fileInfo* GetFileInfo(char *filename) {
	if (filename == NULL) {
		return NULL;
	}

	DE *parent  = NULL;
	int index = -1; 
	char *lastElementName = NULL;

    	// Resolve the file path
    	if (ParsePath(filename, &parent, &index, &lastElementName) != 0 || index < 0) {
        	return NULL; // File not found
    	}

    	DE *fileEntry = &parent[index]; // Directory entry for the file
    	if (fileEntry == NULL) {
       		return NULL; // File entry is invalid
 	}

    	// Populate the fileInfo structure
    	fileInfo *fi = malloc(sizeof(fileInfo));
    	if (fi == NULL) {
 	       return NULL; // Memory allocation failure
    	}

    	fi->fileSize = fileEntry->size;
    	fi->location = fileEntry->location;
    	strncpy(fi->name, fileEntry->name, sizeof(fi->name));

    	return fi;
}

int createFile(char *filename) {
    	if (filename == NULL) {
        	return -1; // Invalid filename
    	}

    	DE *parent = NULL;    // Parent directory
    	int index = -1;       // Index of the new file
    	char *lastElementName = NULL;

    	// Parse the path to determine the parent directory
    	if (ParsePath(filename, &parent, &index, &lastElementName) != 0) {
        	return -1; // Invalid path
    	}

    	// Check if file already exists
    	if (index >= 0) {
        	return -1; // File already exists
    	}

    	// Find a free directory entry in the parent directory
    	for (int i = 0; i < MAX_ENTRIES; i++) {
        	if (parent[i].name[0] == '\0') {
            		// Populate the new directory entry
            		strncpy(parent[i].name, lastElementName, MAX_NAME_LEN);
            		parent[i].isDir = false;
            		parent[i].size = 0;
            		parent[i].location = allocateBlock(); // Allocate a block for the file
            		parent[i].creation_time = time(NULL);
            		parent[i].modification_time = parent[i].creation_time;
            		parent[i].access_time = parent[i].creation_time;

            		return 0; // Success
        	}
    }

    return -1; // No space in the directory
}

int truncateFile(fileInfo *fi) {
    	if (fi == NULL) {
        	return -1; // Invalid fileInfo
    	}

    	// Free the blocks associated with the file
    	for (int i = 0; i < (fi->fileSize + BLOCK_SIZE - 1) / BLOCK_SIZE; i++) {
        	freeBlock(fi->location + i); // Free each block
    	}

    	// Reset the file size to zero
    	fi->fileSize = 0;
    	return 0;
}

	
// Interface to open a buffered file
// Modification of interface for this assignment, flags match the Linux flags for open
// O_RDONLY, O_WRONLY, or O_RDWR
b_io_fd b_open(char *filename, int flags) {
    if (filename == NULL)
        return -1;

    b_io_fd fd;
    fileInfo *fi;

    if (startup == 0)
        b_init();  // Initialize the system

    // Get file information
    fi = GetFileInfo(filename);

    // Handle O_CREAT
    if (flags & O_CREAT) {
    if (fi == NULL) {
        int creationStatus = createFile(filename);  // Attempt to create the file
        if (creationStatus == -1) {
            return -1;  // Return an error if file creation failed
        }

        // Try retrieving file information again
        fi = GetFileInfo(filename);
        if (fi == NULL) {
            return -1;  // Return an error if file info is still unavailable
        }
    }
}


    // If file doesn't exist and O_CREAT wasn't specified
    if (fi == NULL) {
        return -1;  // File not found
    }

    // Handle O_TRUNC
    if (flags & O_TRUNC) {
        if (truncateFile(fi) == -1) {
            return -1;  // Failed to truncate file
        }
    }

    // Get a free FCB
    fd = b_getFCB();
    if (fd < 0) {
        return -1;  // Out of file handles
    }

    // Allocate buffer
    char *buf = malloc(B_CHUNK_SIZE);
    if (buf == NULL) {
        fcbArray[fd].fi = NULL;  // Release FCB
        return -1;               // Memory allocation failed
    }

    // Initialize the FCB
    fcbArray[fd].fi = fi;
    fcbArray[fd].buf = buf;
    fcbArray[fd].index = 0;
    fcbArray[fd].buflen = 0;
    fcbArray[fd].currentBlock = 0;
    fcbArray[fd].flags = flags;
    switch (flags & (O_RDONLY | O_WRONLY | O_RDWR)) {
    case O_RDONLY:
        fcbArray[fd].mode = O_RDONLY;
        break;
    case O_WRONLY:
        fcbArray[fd].mode = O_WRONLY;
        break;
    case O_RDWR:
        fcbArray[fd].mode = O_RDWR;
        break;
    default:
        fcbArray[fd].mode = 0;         // Default or invalid mode
        break;
}

    // Calculate total number of blocks
    fcbArray[fd].numBlocks = (fi->fileSize + (B_CHUNK_SIZE - 1)) / B_CHUNK_SIZE;

    // Handle O_APPEND
    if (flags & O_APPEND) {
        // Set the file position to the end of the file
        fcbArray[fd].index = fi->fileSize % B_CHUNK_SIZE;
        fcbArray[fd].currentBlock = fcbArray[fd].numBlocks - 1;

        // Load the last block into the buffer if needed
        if (fi->fileSize > 0) {
            int blocksRead = LBAread(fcbArray[fd].buf, 1, fi->location + fcbArray[fd].currentBlock);
            if (blocksRead <= 0) {
                free(fcbArray[fd].buf);
                fcbArray[fd].buf = NULL;
                fcbArray[fd].fi = NULL;
                return -1;  // Error reading the last block
            }
            fcbArray[fd].buflen = fi->fileSize % B_CHUNK_SIZE;
        }
    }

    return fd;
}

// Interface to seek function	
int b_seek (b_io_fd fd, off_t offset, int whence) {

	if (startup == 0) b_init();  //Initialize our system

	// check that fd is between 0 and (MAXFCBS-1)
	if ((fd < 0) || (fd >= MAXFCBS))
		{
		printf("Error: Invalid file descriptor");
		return (-1); 		//invalid file descriptor
		}

	// Reference to the file control block
	b_fcb *fcb = &fcbArray[fd];

	if (fcb->buf == NULL) {

		// File is not open
		printf("Error: File not open\n");
		return -1;
	}

    	// Handle the seek based on whence
    	switch (whence) {

	// Seek from the beginning of the file
        	case SEEK_SET:
            		if (offset < 0 || offset > fcb->fileSize) {
                		printf("Error: Offset out of bounds\n");
                		return -1;
            		}
            		fcb->index = offset;
            		break;

		// Seek from the current position
        	case SEEK_CUR:
            		if (fcb->index + offset < 0 || fcb->index + offset > fcb->fileSize) {
                		printf("Error: Offset out of bounds\n");
                		return -1;
            		}
            		fcb->index += offset;
            		break;

		// Seek from the end of the file
        	case SEEK_END:
            		if (offset > 0 || fcb->fileSize + offset < 0) {
                		printf("Error: Offset out of bounds\n");
                		return -1;
            		}
            		fcb->index = fcb->fileSize + offset;
            		break;

        	default:
            		printf("Error: Invalid whence value\n");
            		return -1;
    	}

    	// Check if the position has crossed block boundaries
    	uint32_t newBlock = fcb->index / B_CHUNK_SIZE;
    	if (newBlock != fcb->currentBlock) {

        // Code to reload the buffer from the new block goes here
        fcb->currentBlock = newBlock;
    	}

	// Return the new file position
    	return fcb->index;

}

// Interface to write function	
int b_write (b_io_fd fd, char * buffer, int count)
	{
	if (startup == 0) b_init();  //Initialize our system

	// check that fd is between 0 and (MAXFCBS-1)
	if ((fd < 0) || (fd >= MAXFCBS))
		{
		return (-1); 					//invalid file descriptor
		}

    b_fcb *fcb = &fcbArray[fd];  // Referencing the file control block
    int inputBufferOffset = 0;
    int totalBytesWritten = 0;
    int bytesToCopy;

    // Remaining bytes in the current block
    int bytesLeftInBlock = vcb.block_size - (fcb->fileSize % vcb.block_size);

    // Allocate memory for the file block buffer
    char *blockBuffer = malloc(vcb.block_size);
    if (blockBuffer == NULL) {
        return -1;  // Memory allocation failure
    }

    // Write remaining bytes into the partially filled block (if any)
    if (bytesLeftInBlock > 0) {
        LBAread(blockBuffer, 1, fcb->currentBlock);  // Read current block
        bytesToCopy = (bytesLeftInBlock < count) ? bytesLeftInBlock : count;
        memcpy(blockBuffer + (vcb.block_size - bytesLeftInBlock), buffer, bytesToCopy);

        LBAwrite(blockBuffer, 1, fcb->currentBlock);  // Write back to disk
        fcb->fileSize += bytesToCopy;  // Update file size
        totalBytesWritten += bytesToCopy;
        inputBufferOffset += bytesToCopy;
        count -= bytesToCopy;
    }

    // Write full blocks from the remaining input
    while (count > 0) {
        memset(blockBuffer, 0, vcb.block_size);  // Clear block buffer

	int nextBlock = allocateBlock();
        if (nextBlock == 0) { // Check if no blocks are available
            printf("Error: No free blocks available.\n");
            free(blockBuffer);
            return totalBytesWritten;
        }

        fcb->currentBlock = nextBlock;  // Allocate next block
        bytesToCopy = (count < vcb.block_size) ? count : vcb.block_size;
        memcpy(blockBuffer, buffer + inputBufferOffset, bytesToCopy);

        LBAwrite(blockBuffer, 1, fcb->currentBlock);  // Write the block to disk
        fcb->fileSize += bytesToCopy;  // Update file size
        totalBytesWritten += bytesToCopy;
        inputBufferOffset += bytesToCopy;
        count -= bytesToCopy;
    }

    // Free allocated memory
    free(blockBuffer);

    return totalBytesWritten;  // Returning the total number of bytes written
}



// Interface to read a buffer

// Filling the callers request is broken into three parts
// Part 1 is what can be filled from the current buffer, which may or may not be enough
// Part 2 is after using what was left in our buffer there is still 1 or more block
//        size chunks needed to fill the callers request.  This represents the number of
//        bytes in multiples of the blocksize.
// Part 3 is a value less than blocksize which is what remains to copy to the callers buffer
//        after fulfilling part 1 and part 2.  This would always be filled from a refill 
//        of our buffer.
//  +-------------+------------------------------------------------+--------+
//  |             |                                                |        |
//  | filled from |  filled direct in multiples of the block size  | filled |
//  | existing    |                                                | from   |
//  | buffer      |                                                |refilled|
//  |             |                                                | buffer |
//  |             |                                                |        |
//  | Part1       |  Part 2                                        | Part3  |
//  +-------------+------------------------------------------------+--------+

int b_read(b_io_fd fd, char *buffer, int cnt) {
    if (startup == 0) 
		b_init();  

    // Validate file descriptor
    if ((fd >= MAXFCBS)||(fd <= -1)) {
        return -1;  
    }

    b_fcb *bfcb = &fcbArray[fd];

    // Check if the file is open
    if (bfcb->buf == NULL) {
        return -1;  // File not open
    }

    // Handle EOF
	if(bfcb->fileSize <= bfcb->index) {
		return 0;
	}

    // Calculate the actual number of bytes to read (don't exceed EOF)
    int btr = cnt;
	if (bfcb->fileSize < bfcb->index + cnt) {
        btr = bfcb->fileSize - bfcb->index;
    }

    int br = 0;  // Total bytes read so far
    int bufRemain, bFromBuf, fullBlocks;
	
	if(btr < bufRemain)
		bFromBuf = btr;
	else
		bFromBuf = bufRemain;

    if (bFromBuf > 0) {
        memcpy(buffer, (bfcb->index % B_CHUNK_SIZE) + bfcb->buf, bFromBuf);
		br += bFromBuf;
        bfcb->index += bFromBuf;
        btr -= bFromBuf;
    }

    //Read full blocks directly into the caller's buffer
    fullBlocks = btr / B_CHUNK_SIZE;
	
    if (fullBlocks > 0) {
        int blocksRead = LBAread(br + buffer, fullBlocks, bfcb->currentBlock + 1 + bfcb->fi->location);
        if (blocksRead < 1) {
            return -1;  // Error reading from disk
        }
		
		btr -= blocksRead * B_CHUNK_SIZE;
        br += (B_CHUNK_SIZE * blocksRead);
        bfcb->index += (B_CHUNK_SIZE * blocksRead);
    }

    //Fill remaining bytes from a refilled buffer
    if (btr > 0) {
        bfcb->currentBlock++;
        int blocksRead = LBAread(bfcb->buf, 1, bfcb->currentBlock + bfcb->fi->location);
        if (blocksRead <= 0) {
            return -1;  // Error reading from disk
        }
        bfcb->buflen = B_CHUNK_SIZE;

        memcpy(buffer + br, bfcb->buf, btr);
        bfcb->index += btr;
        br += btr;
        btr = 0;
    }

    return br;  // Return the total number of bytes read
}

	
// Interface to Close the file	
// Interface to Close the file
int b_close(b_io_fd fd) {
    // Validate the file descriptor
    if ((fd < 0) || (fd >= MAXFCBS)) {
        return -1;  // Invalid file descriptor
    }

    b_fcb *fcb = &fcbArray[fd];

    // Check if the file is open
    if (fcb->fi == NULL) {
        return -1;  // File not open
    }

    // Flush any pending writes (if write buffering is implemented)
    if ((fcb->flags & (O_WRONLY | O_RDWR)) && (fcb->buflen > 0)) {
        int blocksWritten = LBAwrite(fcb->buf, 1, fcb->fi->location + fcb->currentBlock);
        if (blocksWritten <= 0) {
            // Error writing to disk
            // Decide whether to proceed or return an error
            // For now, we'll proceed to clean up
        }
    }

    // Free the buffer
    if (fcb->buf != NULL) {
        free(fcb->buf);
        fcb->buf = NULL;
    }

    // Release the file info (if appropriate)
    fcb->fi = NULL;  // Indicates a free FCB

    // Reset other fields
    fcb->index = 0;
    fcb->buflen = 0;
    fcb->currentBlock = 0;
    fcb->numBlocks = 0;
    fcb->flags = 0;
    fcb->mode = 0;

    return 0;
}
