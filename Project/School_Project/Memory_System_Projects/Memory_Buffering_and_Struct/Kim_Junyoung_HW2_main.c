/**************************************************************
* Class::  CSC-415-01 Summer 2024
* Name::Junyoung Kim
* Student ID::920303420
* GitHub-Name::coder-j-0090
* Project:: Assignment 2 – Stucture in Memory and Buffering
*
* File:: Kim_Junyoung_HW2_main.c
*
* Description:: This program uses structures, pointers,
*  character strings, enumerated types, bitmap fields,
*  and buffering data into blocks
*
**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <assignment2.h>

int main(int argc, char *argv[])
{
	//Need to check if all arguments(first name, last name, and message) are entered,
	// because running program when it doesn't meet requirement is waste of resources
	if(argc < 4)
	{
		printf("Not all required arguments are provided!");
		return -1;
	}

	//Bring struct to main.c and allocate the memory exact size of struct.
	struct personalInfo *student = malloc(sizeof(struct personalInfo));
	//Instruction said first name and last name should be populated
	// from 1st and 2nd command line argument
	student->firstName = argv[1];
	student->lastName = argv[2];

	//Instruction said assign student ID and gradelevel
	student->studentID = 920303420;
	student->level = SENIOR;

	student->languages = KNOWLEDGE_OF_C|KNOWLEDGE_OF_JAVA|KNOWLEDGE_OF_JAVASCRIPT
			      |KNOWLEDGE_OF_PYTHON|KNOWLEDGE_OF_SQL|KNOWLEDGE_OF_HTML;

	//Use strncpy and third parameter as 100, so we limit the letter to 100.
	strncpy(student->message, argv[3], 100);

	//Instruction said return 0 if writePersonalInfo function works, so used if statement to check if it succeeded.
	if(writePersonalInfo(student)!=0)
	{
		printf("Error! Something went wrong!");
		return -1;
	}

	//Every malloc should have corresponding free
	free(student);

	//Create Buffer BLOCK_SIZE with malloc to allocate buffer

	//Allocate memory for buffer with malloc
	char *stringBuffer = malloc(BLOCK_SIZE);
	//Initialize the size of Buffer
	size_t sizeOfBuffer = BLOCK_SIZE;
	//track the position of buffer
	size_t bufferPos = 0;

	const char *currentStr;

	//Run while there's string left, but stop as soon as there's nothing left.
	//Retrieve data and check end of data at once
	while(currentStr=getNext())
	{
		//length of current String
		size_t remainder = strlen(currentStr);
		//Position of current String(Initialization)
		size_t stringPos = 0;

		//Repeat until buffer get all of currentStr
		while(1)
		{
			//if remaining string fit into available Buffer space
			if(remainder < sizeOfBuffer)
			{
				//copy remaining to Buffer and update position
				memcpy(stringBuffer + bufferPos, currentStr + stringPos, remainder);

				//Need to update position and buffer size after each memcpy
				//move the position of Buffer
				bufferPos += remainder;
				//remove buffer's space as much as used
				sizeOfBuffer -= remainder;
				//Exit after string is fully copied
				break;
			}

			//Copy as much string as possible in buffer
			memcpy(stringBuffer + bufferPos, currentStr +  stringPos, sizeOfBuffer);
			commitBlock(stringBuffer);
			//Update as much as remainder decrease and string position moved
			remainder -= sizeOfBuffer;
			stringPos += sizeOfBuffer;
			//Need to reset the size and position for each chunk to work properly
			sizeOfBuffer=BLOCK_SIZE;
			bufferPos = 0;
		}
	}

	//If BLOCK_SIZE have some left over space, use commitBlock to process rest of them.
	if(sizeOfBuffer<BLOCK_SIZE)
	{
		commitBlock(stringBuffer);
	}

	//Free allocated memory
	free(stringBuffer);
	//Verification
	return checkIt();
}
