/**************************************************************
* Class::  CSC-415-03 Fall 2024
* Name:: Justin Ho, Junyoung Kim, Ryan Flannery. Bilguun Bayasgalan
* Student IDs:: 922266680, 920303420, 921824732, 922564900
* GitHub-Name:: justinh128
* Group-Name:: Innov8
* Project:: File System
*
* File:: free_space.c
*
* Description:: Free Space management including initialization
  and writing to disk.
*
**************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "free_space.h"
#include "vcb.h"
#include "fsLow.h"

#define BLOCK_SIZE 512

static uint32_t totalBlocks = 0;
static unsigned char *freeSpaceMap = NULL;

uint32_t initializeFreeSpace(uint32_t bitmap_blocks, uint32_t block_size){

    // Allocating memory for the free space bit map we need 5 blocks for the entire bit map
    // Need 2442 bytes for our 19,531 possible bits. Memory is allocated in 512 byte blocks
    printf("Allocating free space bitmap with %u blocks of size %u bytes\n", bitmap_blocks, block_size);

    unsigned char *freeSpaceMap = (unsigned char *) malloc(bitmap_blocks * block_size);

    // Debug/Testing
    if(freeSpaceMap == NULL){
        printf("Memory allocation failed!");
        exit(EXIT_FAILURE);
    }

    printf("freeSpaceMap allocated at address %p with size %u bytes\n", (void *)freeSpaceMap, bitmap_blocks * block_size);

    // Setting all bits to 0, marking all blocks as free from the start
    // If a bit is set to 1 it means the corresponding block is being used
    memset(freeSpaceMap, 0, bitmap_blocks * block_size);

    // Initializing the first 6 blocks which are reserved for system use
    // Block 0 is for the VCB
    // Blocks 1-5 for the free space bit map
    for(int i = 0; i < 6; i ++){
        int byteLocation = i / 8;  // Checking which byte contains the current bit
        int bitLocation = i % 8;   // Checking the bit position within that byte

    if (byteLocation >= bitmap_blocks * block_size) {
        printf("Error: Attempted out-of-bounds write in freeSpaceMap at byte location %d\n", byteLocation);
        free(freeSpaceMap);
        return 0;
    }
        unsigned char mask = (1 << bitLocation); // Mask is created to to isolate the specific bit we want to set to 1
        freeSpaceMap[byteLocation] |= mask; // Setting the bit to 1 to mark the block used
        printf("Setting bit at byte location %d, bit location %d\n", byteLocation, bitLocation);

    }

    // LBAWrite() the free space bitmap to disk Blocks 1-5
    int blocksSuccessfullyWritten = LBAwrite(freeSpaceMap, bitmap_blocks, 1);
    // Verifying that exactly 5 blocks of the free space bitmap were written to the disk
    // If the number is not equal to 5 there is an error writing to the disk
    if(blocksSuccessfullyWritten != bitmap_blocks){
        printf("Could not write the entire free space bitmap to disk! \n");
	free(freeSpaceMap);
        return 0;
    }

    // free allocated memory after testing
    free(freeSpaceMap);
    printf("Successfully freed freeSpaceMap at address %p\n", (void *)freeSpaceMap);

    return 1;
}

// Allocate a block
uint32_t allocateBlock() {
    for (uint32_t i = 0; i < totalBlocks; i++) {
        uint32_t byteIndex = i / 8;
        uint32_t bitIndex = i % 8;

        if (!(freeSpaceMap[byteIndex] & (1 << bitIndex))) {
            // Mark block as allocated
            freeSpaceMap[byteIndex] |= (1 << bitIndex);
            return i;
        }
    }
    return 0; // No free blocks available
}

// Free a block
void freeBlock(uint32_t blockNumber) {
    if (blockNumber < totalBlocks) {
        uint32_t byteIndex = blockNumber / 8;
        uint32_t bitIndex = blockNumber % 8;

        // Mark block as free
        freeSpaceMap[byteIndex] &= ~(1 << bitIndex);
    }
}
