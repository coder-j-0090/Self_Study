/**************************************************************
* Class::  CSC-415-0# Fall 2024
* Name::Junyoung Kim
* Student ID::920303420
* GitHub-Name::coder-j-0090
* Project:: Assignment 1 – Command Line Arguments
*
* File:: Kim_Junyoung_HW1_main.c
*
* Description::This assignment is to write a C program that accepts 
* arguments via the command line and then displays each of those arguments 
* to the terminal along with how many arguments there are.
*
**************************************************************/

//Basic standard input and output library
#include <stdio.h>

//Main function that counts the number of words(arguments) 
//using int argc and char *argv[] that will save values
int main(int argc, char *argv[])
{
	printf("There were %d arguments on the command line.\n",argc);
	//Loop to get whole arguments and print each argument in new line
	for(int i=0;i<argc;i++)
	{
		printf("Argument %02d: %s \n", i, argv[i]);
	}
	return 0;
}
