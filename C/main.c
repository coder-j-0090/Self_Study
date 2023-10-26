//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

#include <stdio.h>

struct student
{
    int Kor,Eng,Math;           //int : 정수
    float avg;                  //float : 실수
    char grd;                   //char : 글자
};


int sum(int a, int b, int c)
{
    int d;
    d=a+b+c;
    return d;
}


double avg(int d)
{
    double f;
    f=d/3.0;
    return f;
}


char grade(double s)
{
    if(s>=90)
    {
        return 'A';
    }
    else if(s>=80)
    {
        return 'B';
    }
    else if(s>=70)
    {
        return 'C';
    }
    else if(s>=60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}


int main()
{
    struct student p[3];
    int a,b,c,z,f,s;
    double d;
    scanf("%d %d %d", &a, &b, &c);
    s = sum(a,b,c);
    printf("sum : %d",s);
    d= avg(s);
    printf("avg : %f",d);
    z= grade (d);
    printf("Letter Grade : %c",z);
    printf("\n");
    return 0;
}

