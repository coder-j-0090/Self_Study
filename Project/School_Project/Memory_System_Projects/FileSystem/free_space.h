/**************************************************************
* Class::  CSC-415-03 Fall 2024
* Name:: Justin Ho, Junyoung Kim, Ryan Flannery. Bilguun Bayasgalan
* Student IDs:: 922266680, 920303420, 921824732, 922564900
* GitHub-Name:: justinh128
* Group-Name:: Innov8
* Project:: File System
*
* File:: free_space.h
*
* Description:: Header file containing initialize free space
  function prototype.
*
**************************************************************/
#ifndef FREE_SPACE_H
#define FREE_SPACE_H

// Function prototype
uint32_t initializeFreeSpace(uint32_t bitmap_blocks, uint32_t block_size);
uint32_t allocateBlock(void);
void freeBlock(uint32_t blockNumber);
#endif
