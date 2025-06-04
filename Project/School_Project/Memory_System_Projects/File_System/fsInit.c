/**************************************************************
* Class::  CSC-415-03 Fall 2024
* Name:: Justin Ho, Junyoung Kim, Ryan Flannery. Bilguun Bayasgalan
* Student IDs:: 922266680, 920303420, 921824732, 922564900
* GitHub-Name:: justinh128
* Group-Name:: Innov8
* Project:: File System
*
* File:: fsInit.c
*
* Description:: This is the main driver for the file system.
  It is where the system is initialized including the VCB, root
  directory, and free space. 
*
**************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

#include "fsLow.h"
#include "mfs.h"
#include "vcb.h"
#include "free_space.h"
#include "root.h"

#define BLOCK_SIZE 512
#define VOLUME_SIZE 1024 * 1024 * 10 // 10MB
#define BITMAP_BLOCKS 5
#define ROOT_DIR_BLOCK 6
struct volume_control_block vcb;
	
int initFileSystem (uint64_t volume_size, uint64_t block_size) {
    printf("Initializing file system with volume size: %lu and block size: %lu\n", volume_size, block_size);
    
    // Initialize the volume if it is missing
    if (startPartitionSystem("SampleVolume", &volume_size, &block_size) < 0) {
        printf("Error: Failed to start partition system with SampleVolume.\n");
        return -1;
    }

    // Using malloc, allocate memory for the VCB
    printf("Allocating memory for VCB of size %lu bytes\n", (unsigned long)BLOCK_SIZE);
    struct volume_control_block *vcb = malloc(BLOCK_SIZE);
    if (!vcb) {
        printf("Error: Unable to allocate memory for VCB.\n");
        closePartitionSystem();
        return -1;
    }
    printf("VCB allocated at address %p\n", (void *)vcb);

    // Read the VCB from block 0 to see if the volume is already formatted
    int read_result = LBAread(vcb, 1, 0);
    printf("Read result: %d\n", read_result);

    // Check if we need to initialize the volume
    if (read_result != 1 || vcb->signature != VCB_SIGNATURE) {
        printf("Initializing new file system...\n");
        
        // Volume is unformatted, so we need to initialize it
        memset(vcb, 0, BLOCK_SIZE);  // Clear the VCB first
        vcb->volume_size = volume_size;
        vcb->block_size = BLOCK_SIZE;
        vcb->total_blocks = volume_size / BLOCK_SIZE;
        vcb->free_blocks = vcb->total_blocks - 1;  // Reserving one block for the VCB itself
        vcb->bitmap_start = 1;  // Bitmap starts at block 1
        vcb->bitmap_size = BITMAP_BLOCKS;
        vcb->root_directory = ROOT_DIR_BLOCK;  // Root directory starts after bitmap
        vcb->creation_time = time(NULL);
        vcb->modification_time = vcb->creation_time;
        vcb->signature = VCB_SIGNATURE; // Set the signature to indicate volume is formatted
        // strncpy(vcb->volume_id, "SampleVolume", 16);

        // Initialize free space bitmap and set starting block in VCB
        printf("Initializing free space bitmap...\n");
        if (!initializeFreeSpace(BITMAP_BLOCKS, block_size)) {
            printf("Error: Failed to initialize free space bitmap\n");
            free(vcb);
            closePartitionSystem();
            return -2; 
        }

        // Initialize root directory
        printf("Initializing root directory...\n");
	struct RootDirectory rootDirStruct;
        RootDirecInit(&rootDirStruct, vcb->root_directory);
        
        // Write the root directory to disk
        if (writeRootToVol("SampleVolume", &rootDirStruct) < 0) {
            printf("Error: Failed to write root directory to disk.\n");
            free(vcb);
            closePartitionSystem();
            return -3;
        }

        // Write the initialized VCB to block 0
        printf("Writing VCB to disk...\n");
        if (LBAwrite(vcb, 1, 0) != 1) {
            printf("Error: Failed to write VCB to disk\n");
            free(vcb);
            closePartitionSystem();
            return -4; // Return -4 to indicate write error
        }

        // Set rootDir and curDir
        rootDir = malloc(sizeof(struct RootDirectory));
        if (!rootDir) {
            printf("Error: Unable to allocate memory for rootDir.\n");
            free(vcb);
            closePartitionSystem();
            return -5;
        }
        memcpy(rootDir, &rootDirStruct, sizeof(struct RootDirectory));
        curDir = rootDir; // Set current directory to root

        printf("File system initialized successfully\n");

    } else {
        // Load existing file system
        printf("Loading existing file system...\n");
        printf("VCB Signature: 0x%X\n", vcb->signature);
        printf("Volume ID: %s\n", vcb->volume_id);
        printf("Total blocks: %lu\n", vcb->total_blocks);

        // Load root directory from disk
        rootDir = malloc(sizeof(struct RootDirectory));
        if (!rootDir) {
            printf("Error: Unable to allocate memory for rootDir.\n");
            free(vcb);
            closePartitionSystem();
            return -6;
        }
        if (LBAread(rootDir, 1, vcb->root_directory) != 1) {
            printf("Error: Failed to load root directory from disk.\n");
            free(vcb);
            free(rootDir);
            closePartitionSystem();
            return -7;
        }

        curDir = rootDir; // Set current directory to root
        printf("Root directory loaded successfully.\n");
    }

    // Clean up
    free(vcb);
    return 0;
}
void exitFileSystem ()
	{
	printf ("System exiting\n");
	closePartitionSystem();
	}
