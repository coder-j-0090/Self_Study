//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

#include <stdio.h>


int main()
{
    int dataa[5]={8,4,9,2,5};
    char str[5]="ahdsd";
    int i=0;
        
    while(i<5)
    {
        printf("%d ", *(dataa+i));
        i++;
    }
        
    i=0;
    while(i<5)
    {
        printf("%c ", *(str+i));
        i++;
    }
    printf("\n");
    return 0;
}
