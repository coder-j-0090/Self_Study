/**************************************************************
* Class::  CSC-415-01 Fall 2024
* Name:: Junyoung Kim
* Student ID:: 920303420
* GitHub-Name:: coder-j-0090
* Project:: Assignment 3 – Simple Shell with Pipes
*
* File:: Kim_Junyoung_HW3_main.c
*
* Description:: This program should implement shell that reads 
*		user input, forks a process to execute commands
*		using execvp(), and waits for child process to finish.
*		Should support command piping, handle up to 4 command
*		and manage input 159-byte buffer.
**************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 159

/*
 * Tokenize input into string array.
 */
char **command_tokenization(char *com)
{
    int count = 0;

    // New line should be considered as one line
    if (com[strlen(com) - 1] == '\n')
    {
        com[strlen(com) - 1] = '\0';
    }

    // Create double pointer to store array of tokens.
    char **store_tokens = NULL;
    char *token = strtok(com, " ");

    while (token != NULL)
    {
        // For each token found, reallocate memory and save token.
        store_tokens = realloc(store_tokens, (count + 1) * sizeof(char *));
        store_tokens[count] = token;
        count++;
        token = strtok(NULL, " ");
    }

    // Reallocate memory once more to store the null element.
    store_tokens = realloc(store_tokens, (count + 1) * sizeof(char *));
    store_tokens[count] = NULL;

    return store_tokens;
}

//Print process id and display error message
void print(pid_t process_id, int status)
{
    printf("Child %d, exited with %d\n", process_id, WEXITSTATUS(status));
    if (errno = WEXITSTATUS(status))
    {
        perror("execvp");
    }
}

int main(char argc, char * argv[])
{
	const char *prompt;

	//Accept a command line argument if argument is more than one word.
	// If no value is specified use “$ ” as the prompt.
	if(argc > 1)
	{
		prompt = argv[1];
	}

	else
	{
		prompt = "> ";
	}

	while(1)
	{
		printf("%s", prompt);
		char input[BUFFER_SIZE];

		//Check EOF
		if(!fgets(input, BUFFER_SIZE, stdin))
		{
			printf("EOF reached, exiting\n");
			exit(0);
		}

		//Split input into pipes

        	char *input_ptr = NULL;
        	char *com = strtok_r(input, "|", &input_ptr);
        	size_t len = strlen(com);

        	// Remove the newline character at the end.
        	if (com[len - 1] == '\n')
        	{
            		com[len - 1] = '\0';
        	}

        	// Exit shell, when prompted.
        	if (strcmp(input, "exit") == 0)
        	{
            		exit(0);
        	}

        	if (strlen(input) == 0)
        	{
            		printf("Please pass in an argument\n");
            		continue;
        	}

		while (com != NULL)
        	{
            		char **tokens = command_tokenization(com);

            		com = strtok_r(NULL, "|", &input_ptr);

			//If there's only one command, then no piping needed.
            		if (com == NULL)
            		{
		                pid_t process_id = fork();
                		int status;

				if(process_id != 0)
				{
					//Wait to execute and print process id
					pid_t child_process_id = wait(&status);
					if(WIFEXITED(status))
					{
						print(child_process_id, status);
					}
				}
				else
				{
					execvp(tokens[0], tokens);
					free(tokens);
					exit(errno);
				}

            		}

			else
            		{
               			// Create child process and pipe with 2 file descriptor
               			int fd[2];
                		pipe(fd);
                		pid_t process_id2 = fork();
                		int status2;

                		if (process_id2 == 0)
               			{
                    			// In the child process, duplicate the write end of the pipe
                    			// to the stdout and close unused pipes.
                    			dup2(fd[1], STDOUT_FILENO);
                    			close(fd[0]);
                   			close(fd[1]);
                    
					// Then, execute the command.
                    			execvp(tokens[0], tokens);
                    			free(tokens);
                    			exit(errno);
                		}
                		else
                		{
 	                   		// In the parent, wait for the process to execute.
                    			close(fd[1]);
		                	pid_t child_process_id3 = wait(&status2);

                    			if (WIFEXITED(status2))
                    			{
                    				print(child_process_id3, status2);
                    			}
                   			free(tokens);
                   			// Again, tokenize the command to execute.
                    			char **tokens2 = command_tokenization(com);
                    			pid_t process_id3 = fork();
                   			int status;
                   			if (process_id3 == 0)
                    			{
                        			// In the child process, duplicate the write end to
                        			// std in and close unused pipes.
                        			close(STDIN_FILENO);
                        			dup2(fd[0], STDIN_FILENO);
                        			close(fd[0]);
                        			execvp(tokens[0], tokens);
                        			free(tokens);
                        			exit(errno);
                    			}
                    			else
                    			{
        			                // In the parent, close the remaining two pipes and
                			        // wait for the process to finish executing.
               				        close(fd[0]);
                			        pid_t child_process_id4 = wait(&status);
                			        if (WIFEXITED(status))
               				        {
         		       		                print(child_process_id4, status);
                        			}
                        			free(tokens);
                    			}
       	        		}
            		}
			// Check if there are any command to run.
            		while (com != NULL)
            		{
                		com = strtok_r(NULL, "|", &input_ptr);
            		}
		}
	}
	return 0;
}
