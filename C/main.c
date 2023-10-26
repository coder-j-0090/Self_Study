//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

#include <stdio.h>

//구조체로 삼각형 무게중심찾기
struct tri              //struct가 들어감으로 인해서 구조체. 데이터 타입을 하나로 묶어 줄 때. 함수 아님
{
    int x[3],y[3];      //꼭지점 좌표 x 3개 y 3개
};


int main()
{
    struct tri t;
    for(int i=0;i<3;i++)
    {
        scanf("%d %d", &t.x[i], &t.y[i]);
    }
    printf("%d %d", (t.x[0]+t.x[1]+t.x[2])/3, (t.y[0]+t.y[1]+t.y[2])/3);

}
