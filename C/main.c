//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

//Area and total side length of rectangle
#include <stdio.h>
#include <stdlib.h>         //Need this to use abs function(absolute value)


struct point{
    int x,y;
};
struct rect{
    struct point p1;
    struct point p2;
};
int main(void)
{
    struct rect r;
    int w,h;
    int area, peri;
    printf("왼쪽 상단 : ");
    scanf("%d %d",&r.p1.x,&r.p1.y);
    printf("우측 하단 : ");
    scanf("%d %d",&r.p2.x,&r.p2.y);
    
    w=abs(r.p2.x-r.p1.x);
    h=abs(r.p2.y-r.p1.y);
    
    area = w*h;
    peri = 2*(w+h);
    
    printf("Area  : %d\n",area);
    printf("Peri  : %d\n",peri);
    
    return 0;
}
