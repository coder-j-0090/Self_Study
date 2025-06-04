/**************************************************************
* Class::  CSC-415-01 Fall 2024
* Name:: Junyoung Kim
* Student ID:: 920303420
* GitHub-Name:: coder-j-0090
* Project:: Assignment 6 – Device Driver
*
* File:: Kim_Junyoung_HW6_main.c
*
* Description:: It works with device driver to perform 
*	        encryption/decryption of input. 
*		Use 'ioctl' to choose mode and read/write.
*		Input string, sends it to device, then print 
*		result.
**************************************************************/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include <stdint.h>

#define IOCTL_SET_MODE _IOW('a', 'a', int32_t*)
#define DEVICE "/dev/string_encryptor"

int main()
{
    int mode;
    int file_desc;
    char buf[256];

    //Open device file for reading and writing if it can be open
    file_desc = open(DEVICE, O_RDWR);
    if (0 > file_desc)
    {
        perror("Failed to open the device");
        return -1;
    }

    //Choose mode(encryption or decryption) using ioctl function.
    printf("Enter 1 for Encryption or 0 for Decryption: ");
    scanf("%d", &mode);
    if (0 > ioctl(file_desc, IOCTL_SET_MODE, &mode))
    {
        perror("Failed to set mode");
        return -1;
    }

    //Get input and use write and read function
    // to get& display output.
    printf("Enter the string: ");
    scanf("%s", buf);
    write(file_desc, buf, strlen(buf));
    read(file_desc, buf, sizeof(buf));
    printf("Output: %s\n", buf);

    //close device file descriptor
    close(file_desc);
    return 0;
}
