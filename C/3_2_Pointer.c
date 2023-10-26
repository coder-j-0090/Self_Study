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

//Count the number of Char Variable 'key' in char[] 'data'
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



/*
int count(char*p);


int main()
{
    char data[20];
    int ans;
    scanf("%s",data);       //&안쓰고 하면 시작점 주소 사용
    ans=count(data);         //ans=count(&data[0]);
    printf("%s, ans=%d\n",data,ans);
    return 0;
}


int count(char *p)
{
    char key;
    int i,cnt=0;
    getchar();
    scanf("%c", &key);
    for(i=0;i<20;i++)
    {
        if(key==p[i])           //아니면 if(key==*(p+i) 이게 포인터넉 사용 앞에껀 배열
        {
            cnt++;
        }
    }
    return cnt;
}
 */

