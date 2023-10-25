//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

#include <stdio.h>

int fibo(int num);

int main()
{
    int num,ans;
    scanf("%d", &num);
    ans = fibo(num);
    printf("%d", ans);
    return 0;
}

int fibo(int num)
{
    if(num==1)
    {
        return 1;
    }
    else if(num==2)
    {
        return 2;
    }
    else if(num==3)
    {
        return 4;
    }
    else
    {
        return fibo(num-1)+fibo(num-2)+fibo(num-3);
    }
}
