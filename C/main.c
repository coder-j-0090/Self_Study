//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

#include <stdio.h>
int count(char*p);

int main()
{
    char data[5];
    int i,ans;
    for(i=0;i<5;i++)
    {
        scanf("%c",&data[i]);
    }
    ans=count(data); //ans=count(&data[0]);
    printf("%d\n",ans);
    return 0;
}


int count(char *p)
{
    char key;
    int i,cnt=0;
    getchar();      //It removes the null that should be at last, so it will have 4
    scanf("%c", &key);
    for(i=0;i<5;i++)
    {
        if(key==p[i])           //or if(key==*(p+i)
        {
            cnt++;              //Value of key will increase from 0 to 4, and if there's a same number, variable cnt will increase by 1.
        }
    }
    return cnt;        //cnt is the value of count(data)
}




