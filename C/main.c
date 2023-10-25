//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

#include <stdio.h>

int main()
{
    int a;
    a=10;
    int *p;
    printf("%d\n", a);
    
    a=10;
    printf("%u\n",p);
         
    a=10;
    p=&a;
    printf("%u\n",*p);
    return 0;
}



