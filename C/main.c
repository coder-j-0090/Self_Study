//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

#include <stdio.h>

int main()
{
    //Find the numbers that can be sqaured
    int i,j,cnt;
    for(i=2;i<=100;i++)
    {
        cnt=0;
        for(j=1;j<i;j++)
        {
            if(i%j==0)
            {
                cnt=cnt+1;
            }
        }
        if(cnt==2)
        {
            printf("%d ", i);
        }
    }
         
       
    
    
    //Greatest Common Dinominator
    int num1,num2;
    scanf("%d %d", &num1, &num2);
    while(num1!=num2)
    {
        if(num1>num2)
        {
            num1=num1-num2;
        }
        else
        {
            num2=num2-num1;
        }
    }
    printf("GCD : %d",num1);
    return 0;
}
