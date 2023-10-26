//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

#include <stdio.h>


int main()
{
    int i=0;
    char str[5]="askik";
    int data[5]={34,75,23,4,13};
    while(i<5)
    {
        printf("%c",*(str+i));
        i++;
    }
    printf("\n");
    i=0;
    while(i<5)
    {
        
        i++;
        for(i=0;i<4;i++)
        {
            for(int j=i+1;j<5;j++)
            {
                if(data[i]>data[j])
                {
                    int t=data[i];
                    data[i]=data[j];
                    data[j]=t;
                }
            }
        }
        for(i=0;i<5;i++)
        {
            printf("%d ",*(data+i));
        }
    }
    printf("\n");
    return 0;
}

