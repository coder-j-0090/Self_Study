//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

#include <stdio.h>

int main()
{
    int data[4][4] = {1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16};
    int *p[4],**q,i,j;
    
    p[0]=data[0];           //&data[0][0] is a right way
    p[1]=data[1];           //&data[1][0] 두번쨰 줄에 시작주소를 두번쨰 포인터에 저장한다.
    p[2]=data[2];           //세번쨰줄의 베열에서 [][]뒤의 []를 땐 포인터를 세번째 배열포인터에 저장
    p[3]=data[3];
    
    for(i=0;i<4;i++)        //세로
    {
        for(j=0;j<4;j++)    //가로
        {
            printf("%2d ", *(p[i]+j));
            //Without star, it's an address saved in computer
            // *  (  p  [  i  ]                 +                     j  )
            //내용   세로증가 배열증가                                포인터 연산자(가로증가)
        }
        printf("\n");
    }
    printf("\n");
    q=p;                                        //배열 포인터(p)의 이름은 2차포인터(q)
    for(i=0;i<4;i++)                //세로
    {
        for(j=0;j<4;j++)            //가로
        {
            printf("%2d ", *(*(q+i)+j));
            //*(*(   q       +       i       )       +       j       )
            //      2차포인터  증가   배열포인터
            //(   q       +       i       ) = 배열포인터의 내용 ->2차원배열의 시작주소 + 포인터연산
            //                            *(  2차원 배열의 데이터 주소            ) - > 실제 데이터
        }
        printf("\n");
    }
    return 0;
}


/*
 정리
 Pointer : 메모리의 주소 값을 저장하는 변수. A.K.A 포인터변수.
 Char = 문자형 데이터
 Int = 정수
 Pointer = 주소값


 Int n=100; //변수
 Int *ptr = &n    //포인터


 포인터 연산자
 주소 연산자(&), 참조연산자(*)


 주소연산자(&)
 변수이름 앞에 붙는다.
 해당 변수의 주소값을 반환.


 참조연산자(*)
 포인터의 이름이나 주소앞에 사용. 포인터에 가리키는 주소에 저장된 값 반환.


 포인터 선언
 타입*포인터이름 = &변수이름
 타입*포인터이름 = 주소값


 포인터 참조
 Ex)
 Int x=7;                //변수의 선언
 Int *ptr = &x;                //포인터 선언
 Int *pptr = &ptr;            //포인터 참조


 포인터와 배열의 관계
 배열은 값 변경이 안되는것을 빼고 포인터와 같다.


 배열의 포인터 연산
 Int arr[3] = {10,20,30};
 printf((“%d\n”),arr[0],arr[1],arr[2]);


 for(i=0;i<4;i++)
 {
     printf(“%2d “, *(p[i]+j));
 }
 포인터 배열

 Int main()
 {
 int i,arr_len;
 int num01= 10, num02=20,num03=30;
 int *arr[3]={&num01, &num02, &num03};    //int형 포인터 배열선언

 arr_len=size of (arr)/size of(arr[0]);
 for(i=0;i<arr_len;i++)
 {
     printf(“%d\n”,*arr[i]);
 }


 */
