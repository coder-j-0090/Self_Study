//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

#include <stdio.h>

int main()
{
    int a,b,c;
         scanf("%d %d %d", &a,&b,&c);
         if(a==100||b==100||c==100)
         {
            printf("Special Acceptance");
         }
         else if(a>40&&b>40&&c>40&&(a+b+c)>180)
         {
            printf("Acceptance");
         }
         else
         {
            printf("Fail");
         }

}
