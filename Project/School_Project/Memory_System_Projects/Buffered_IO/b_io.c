/**************************************************************
* Class::  CSC-415-0# Fall 2024
* Name::Junyoung Kim
* Student ID::920303420
* GitHub-Name::coder-j-0090
* Project:: Assignment 5 – Buffered I/O read
*
* File:: b_io.c
*
* Description::Copy certain number of bytes from given file
*		After receiving and counting bytes, program opens
*		the file and reads data into buffer.
*
**************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <memory.h>

#include "b_io.h"
#include "fsLowSmall.h"

#define MAXFCBS 20	//The maximum number of files open at one time


// This structure is all the information needed to maintain an open file
// It contains a pointer to a fileInfo strucutre and any other information
// that you need to maintain your open file.
typedef struct b_fcb
{
	fileInfo *fi; // holds the low level systems file info

	// Add any other needed variables here to track the individual open file
	b_io_fd fd;
	char *buffering;
	size_t first;
	size_t remainder;
	size_t block;
	size_t total_read;

} b_fcb;

//static array of file control blocks
b_fcb fcbArray[MAXFCBS];

// Indicates that the file control block array has not been initialized
int startup = 0;	

// Method to initialize our file system / file control blocks
// Anything else that needs one time initialization can go in this routine
void b_init ()
{
	if (startup)
		return;			//already initialized

	//init fcbArray to all free
	for (int i = 0; i < MAXFCBS; i++)
	{
		fcbArray[i].fi = NULL; //indicates a free fcbArray
	}
		
	startup = 1;
}

//Method to get a free File Control Block FCB element
b_io_fd b_getFCB ()
{
	for (int i = 0; i < MAXFCBS; i++)
	{
		if (fcbArray[i].fi == NULL)
		{
			fcbArray[i].fi = (fileInfo *)-2; 		// used but not assigned
			return i;					//Not thread safe but okay for this project
		}
	}

	return (-1);  //all in use
}

// b_open is called by the "user application" to open a file.  This routine is 
// similar to the Linux open function.  	
// You will create your own file descriptor which is just an integer index into an
// array of file control blocks (fcbArray) that you maintain for each open file.  
// For this assignment the flags will be read only and can be ignored.

b_io_fd b_open (char * filename, int flags)
{
	if (startup == 0) 
		b_init();  //Initialize our system

	fileInfo *fi = GetFileInfo(filename);
	if(fi==NULL)
		return -1;
	
	int fd = b_getFCB();
	
	//If file isn't found
	b_fcb fcb;
	fcb.fi = fi;
	fcb.fd = fd;
	fcb.buffering = malloc(B_CHUNK_SIZE);
	fcb.remainder = B_CHUNK_SIZE;
	fcb.first = 0;
	fcb.total_read = 0;
	fcb.block = LBAread(fcb.buffering, 1, fi->location);
	fcbArray[fd] = fcb;

	return fd;

	//*** TODO ***//  Write open function to return your file descriptor
	//				  You may want to allocate the buffer here as well
	//				  But make sure every file has its own buffer

	// This is where you are going to want to call GetFileInfo and b_getFCB
}



// b_read functions just like its Linux counterpart read.  The user passes in
// the file descriptor (index into fcbArray), a buffer where thay want you to 
// place the data, and a count of how many bytes they want from the file.
// The return value is the number of bytes you have copied into their buffer.
// The return value can never be greater then the requested count, but it can
// be less only when you have run out of bytes to read.  i.e. End of File	
int b_read (b_io_fd fd, char * buffer, int count)
{
	//*** TODO ***//  
	// Write buffered read function to return the data and # bytes read
	// You must use LBAread and you must buffer the data in B_CHUNK_SIZE byte chunks.
		
	if (startup == 0)
		 b_init();  //Initialize our system

	// check that fd is between 0 and (MAXFCBS-1)
	if ((fd < 0) || (fd >= MAXFCBS))
	{
		return (-1); 					//invalid file descriptor
	}

	// and check that the specified FCB is actually in use	
	if (fcbArray[fd].fi == NULL)		//File not open for this descriptor
	{
		return -1;
	}	

	// Your Read code here - the only function you call to get data is LBAread.
	// Track which byte in the buffer you are at, and which block in the file	

	int total_read = 0;

	if (fcbArray[fd].fi->fileSize <=fcbArray[fd].total_read + count)
	{
		count = fcbArray[fd].fi->fileSize - fcbArray[fd].total_read;
	}

	while (fcbArray[fd].remainder && count > total_read)
	{		
		int dup = 0;
		
		if(fcbArray[fd].remainder > count - total_read)
			dup = count - total_read;
		else
			dup = fcbArray[fd].remainder;

		// Copy the remaining bytes into the buffer and update positions.
		memcpy(buffer + total_read, fcbArray[fd].buffering + fcbArray[fd].first, dup);
		
		fcbArray[fd].remainder -= dup;
		fcbArray[fd].first += dup;
		total_read += dup;

		// If there are no remaining space in our buffer, get a new block.
		if (fcbArray[fd].remainder == 0)
		{	
			fcbArray[fd].block += LBAread(fcbArray[fd].buffering, 1, fcbArray[fd].block);
			fcbArray[fd].remainder = B_CHUNK_SIZE;
			fcbArray[fd].first = 0;
		}
	}

	// Update number of bytes read.
	fcbArray[fd].total_read += total_read;
	return total_read;
}
	


// b_close frees and allocated memory and places the file control block back 
// into the unused pool of file control blocks.
int b_close (b_io_fd fd)
{
	//*** TODO ***//  Release any resources

	if (fcbArray[fd].buffering)
		free(fcbArray[fd].buffering);
	fcbArray[fd].fi = NULL;
}
