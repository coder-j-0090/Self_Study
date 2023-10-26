//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

#include <stdio.h>

struct student      //Struct Pointer
{
    int kor,eng,math,tot;           //int : 정수
    float average;                  //float : 실수
    char grd;                   //char : 글자
};
int sum(int kor, int eng, int math);
float avg(int d);
char grade(float s);
int main()
{
    struct student p[4],temp,*sp;
    int i,j;
    for(i=0;i<4;i++)
    {
        scanf("%d %d %d", &p[i].kor, &p[i].eng, &p[i].math );
        p[i].tot=sum(p[i].kor,p[i].eng,p[i].math);
        p[i].average=avg(p[i].tot);
        p[i].grd=grade(p[i].average);
    }
    for(i=0;i<3;i++)
    {
        for(j=i+1;j<4;j++)
        {
            if(p[i].average < p[j].average)
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    
    sp=p;           //sp=&p[0];     
    for(i=0;i<4;i++)
    {
        printf("%d %d %d %d %.2f %c\n",sp->kor, sp->eng, sp->math, sp->tot, sp->average, sp->grd );
            // -> 애로우 연산자. 이게 있으면 일반 구조체 변수처럼 사용 가능.
    }
}
int sum(int kor, int eng, int math)
{
    int d;
    d=kor+eng+math;
    return d;
}


float avg(int d)
{
    float f;
    f=d/3.0;
    return f;
}


char grade(float s)
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


