//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

#include <stdio.h>

int main()
{
    //Pyramid
    int i,j;
    for(i=1;i<=10;i++)
    {
        for(j=i;j<=10;j++)
        {
            printf(" ");
        }
        for(j=1;j<i*2;j++)
            printf("*");
            printf("\n");
    }


}
