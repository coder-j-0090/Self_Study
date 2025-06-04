/**************************************************************
* Class::  CSC-415-03 Fall 2024
* Name:: Justin Ho, Junyoung Kim, Ryan Flannery. Bilguun Bayasgalan
* Student IDs:: 922266680, 920303420, 921824732, 922564900
* GitHub-Name:: justinh128
* Group-Name:: Innov8
* Project:: File System
*
* File:: root.h
*
* Description:: Header file containing root directory struct, 
  directory entry struct, and function prototypes for root.c.
*
**************************************************************/
#ifndef ROOT_H
#define ROOT_H

#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NAME_LEN 255 // Max length for a directory name
#define BLOCK_SIZE 512   // Block size in bytes 
#define MAX_ENTRIES 50   // Maximum number of entries

// Struct for directory entry
typedef struct dir_entry 
{
    char name[MAX_NAME_LEN];      // Name of the directory 
    uint32_t location;	          // Location address
    uint64_t size;                // File Size in bytes
    uint32_t permissions;         // Permissions 
    bool isDir;                   // Boolean to mark if this entry is a directory
    time_t creation_time;         // File creation timestamp
    time_t modification_time;     // Last modification timestamp
    time_t access_time;           // Last access timestamp
    struct dir_entry *parent;
} DE;

// Struct for the root directory
struct RootDirectory 
{
    DE entries[MAX_ENTRIES]; // Array to hold directory entries, such as ".", ".."
    uint32_t entry_count;                  // Number of valid entries 
    uint64_t size;                         // Size of the root directory 
};

extern DE *rootDir;
extern DE *curDir;


// Function prototypes
void RootDirecInit(struct RootDirectory *rootDirStruct, uint32_t rootBlockNum);
int writeRootToVol(const char *volumeFile, struct RootDirectory *rootDirStruct);

#endif
