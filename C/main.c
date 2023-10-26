//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

#include <stdio.h>

struct student // Struct(High to low grade total,average,Letter Grade)
{
    int kor,eng,math,tot;
    float average;
    char grd;
};
int sum(int kor, int eng, int math);
float avg(int d);
char grade(float s);
int main()
{
    struct student p[4],temp;
    int i,j;
    for(i=0;i<4;i++)
    {
        scanf("%d %d %d", &p[i].kor, &p[i].eng, &p[i].math );
        p[i].tot=sum(p[i].kor,p[i].eng,p[i].math);
        p[i].average=avg(p[i].tot);
        p[i].grd=grade(p[i].average);
    }
    for(i=0;i<3;i++)            //Selection Sort
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
    for(i=0;i<4;i++)
    {
        printf("%d %d %d %d %.2f %c\n",p[i].kor, p[i].eng, p[i].math, p[i].tot, p[i].average, p[i].grd );
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


