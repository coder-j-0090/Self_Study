//
//  main.cpp
//  GitUpload
//
//  Created by Junyoung Kim on 2023/11/03.
//


//C++ : Heap(Not done)
#include <iostream>
using namespace std;
//heapify
/*
 * 최댓값은 max_element 함수 쓰면 안되냐? 근데 heap 을 쓰면 최댓값써도 빠르게 다음 최댓값 찾는다.
 * max_Element 는 이진검색으로 O(log2(n))가 시간반복도. 근데 최댓값을 뺴고나면 얘기가 다르다.
 * 빈 공간이 생긴데를 한칸씩 계속 땡긴다. 그래서 그경우 연산을 최소화 하기 위해서 LinkedList. 추가삭제를 간단하게 할 수 있다.
 * 연결선만 조지면 되니까
 * 크기 바꾸기 쉬운게 vector.
 * 그거에 반해서 heap 을 사용하게 되면 무조건 첫번쨰 배열의 칸이 root 라 무조건 한방에 찾는다. 뺴고 나서도 heapify 를 찾고나면 계속 첫번쨰에 최댓값이 들어있다. 나머지 것들 중에서 최댓값을 연속해서 찾아야하는 경우에는 heap 이 좋다.
 * 배열이 쓰기 쉬운데 사이즈가 변화가 안되고 중간에 삭제나 추가를 할 경우 칸을 모두 떙기거나 밀어야 해서 비효율적이다. 중간에 추가삭제를 하기위해 linkedlist 같은걸 만들고, 그 다음에 크기 변화 및 중간삽입을 편하게 하기위해서 만든게 vector.
 *
 * 최대힙. 이진트리(좌측이 우측보다 안커도 된다 이경우는) root가 젤 크다.
 */
//다른거 시킬거 : two pointer, 2분 매칭.
int main()
{
    int heap[] = {6,4,5,1,2,3,9,7,8,10};\
    //Repeat only half. Root compares with left and right.
    
    //heapify.
    int temp = 0;
    for(int i=1;i<10;i++)
    {
//        int root = i;
//        int leftChild = i*2+1;
//        int rightChild = i*2+2;
        int c = i;
        do
        {
            int root = (c-1)/2;
            if(heap[root]<heap[c])
            {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        }while(c!=0);
    }
    
    for(int i=8;i>0;i--)
    {
        temp = heap[0];
        heap[0] = heap[9];
        heap[9] = temp;
        
        int c = (i/2)+1;
        do
        {
            int root = (c-1)/2;
            if( heap[i*2+1] < heap[i*2+2] )
            {
                c++;
            }
        }while(c!=0);
    }
    
    for(int i=0;i<10;i++)
    {
        cout<<"Heap["<<i<<"]: "<<heap[i]<<endl;
    }
}
