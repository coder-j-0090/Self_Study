//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

#include <stdio.h>
//Find how many char 'key' is in char data[20].
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
    int cnt=0;
    getchar();
    scanf("%c", &key);
    while(*p != '\0')           //null : end of input string.
    {
        if(*p==key)             //Count the number of char 'key' in char data[20]
        cnt++;
        p=p+1;                  //pointer operation , +1의 의미는 increase data type size
        //(p=p+1 = p++)
    }
    return cnt;
}


//%s= string(문자열=문장)
//%c= character(한글자)
//%u= unsigned(부호있는(정수형))
//%d= 정수(10진수)
//%o = octal(8진수)
//%h = hexacode(16진수)
//%f= float(실수)

// Integer increase by 4 bytes, char(alphabet) increase by 1 bite.





