//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

//Area and total side length of rectangle
#include <stdio.h>
#include <stdlib.h>         //Need this to use abs function(absolute value)


void hanoi(int n, char from, char temp, char to);
int main()
{
    hanoi(3,'A','B','C');
    return 0;
}


void hanoi(int n, char from, char temp, char to)
{
    if(n==1)        //If only the last plate at the bottom is left
        printf("%c -> %c \n", from, to);     //move from 'from' to 'to'
    else
    {
        hanoi(n-1,from,to,temp);        //Move plate n-1 from 'from' to 'temp'. But, go through 'to'.
        printf("%c -> %c \n", from, to);
        hanoi(n-1,temp,from,to);        //Move the plate at 'temp' to 'to'. Go through 'from'
    }
}


