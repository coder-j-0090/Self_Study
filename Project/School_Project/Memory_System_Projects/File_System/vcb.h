/**************************************************************
* Class::  CSC-415-03 Fall 2024
* Name:: Justin Ho, Junyoung Kim, Ryan Flannery. Bilguun Bayasgalan
* Student IDs:: 922266680, 920303420, 921824732, 922564900
* GitHub-Name:: justinh128
* Group-Name:: Innov8
* Project:: File System
*
* File:: vcb.h
*
* Description:: Header file containing volume control block
  struct.
*
**************************************************************/


#include <time.h> // For timestamps
#include <stdint.h>  // For fixed-width integer types

#define VCB_SIGNATURE 0x1234ABCD  // Signature constant for VCB verification
#define BLOCK_SIZE 512
#define BITMAP_BLOCKS 5

struct volume_control_block {
	uint64_t volume_size; // Total size of the volume in bytes
    	uint32_t block_size; // Size of each block
    	uint64_t total_blocks; // Total number of blocks in the volume
    	uint64_t free_blocks; // Free blocks available
    	uint32_t root_directory; // Block number of the root directory
    	uint32_t bitmap_start; // Starting block of the bitmap
    	uint32_t bitmap_size; // Size of the bitmap in bytes
    	time_t creation_time; // Creation time of the volume
	time_t modification_time; // Last modification time
    	char volume_id[16]; // Volume identifier
	uint32_t signature; // Signature for VCB initialization verification
};

extern struct volume_control_block vcb;
