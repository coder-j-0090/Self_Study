//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

#include <stdio.h>

int main()
{
    //Multiplication Table
    int i,j,a;
    for(i=1;i<=9;i++)
    {
        for(j=2;j<=9;j++)
        {
            a=i*j;
            printf("%d*%d=%2d ",j,i,a);
        }
        printf("\n");
    }
}
