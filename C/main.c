//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

#include <stdio.h>

//Insertion sort(Large to small)
int main()
{
    int data[5]={6,7,8,1,5};
    int i,j,copy;


    for(i=1;i<=4;i++)
    {
        copy=data[i];                   //save the value of data[i] in the variable named 'copy'
        for(j=i-1;j>=0&&copy<data[j];j--)   //Compare j with i-1(the previous one). 'copy' must be smaller than j, and j decreases by 1.
        {
            data[j+1]=data[j];              //If j+1 is bigger, push it back
        }
        data[j+1]=copy;                     
    }
    for(i=0;i<5;i++)
        printf("%d\n", data[i]);
    return 0;
}

