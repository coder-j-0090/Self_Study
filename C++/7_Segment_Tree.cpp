//
//  main.cpp
//  GitUpload
//
//  Created by Junyoung Kim on 2023/11/03.
//


//C++ : SegmentTree
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    //기본 벡터배열 생성
    vector<int> v = {4,2,8,4,3,2,1,7};
    //num 은 v.size(), k는 2의 몇제곱인가 찾기. segmentTree 는 2*2^k 개의 벡터가 있어야한다.
    int num=0, k=0;
    
    while(num<v.size())
    {
        num = pow(2,k);
        k++;
    }
    
    //segmentTree 는 num*2개가 있어야 한다.
    vector<int> segmentTree (num*2);
    int j = 0 ;
    //segmentTree 에 8번 부터 계속집어넣어야한다.
    for(int i=num;i<num*2;i++)
    {
        segmentTree.at(i) = v.at(j);
        //i가 늘어날수록 j 도 늘어난다. 근데 segmentTree 는 8번부터고 v 는 0번부터라 늘어나게 하는 변수이름이 다르다.
        j++;
    }
    //0번까지 집어넣게 되는데 0번은 신경쓰지 마라. 1번까지가 답이니까. 0번은 버린다.
    //vector v 가 8이라 *2하면 16이 나온다. 인덱스 마지막번은 15이므로 -1 해줘야한다.
    for(int i=segmentTree.size()-1;i>0;i--)
    {
        //segmentTree 에서 i/2번째 칸의 값을 setmentTree i/2번째 칸과 segmentTree i번째칸의 값을 합친 값으로 설정해준다.
        segmentTree.at(i/2)=segmentTree.at(i/2)+segmentTree.at(i);
    }
    
    bool check = false;
    while(!check)
    {
        int newIdx, newVal, endCheck;
        
        cout<<"Enter the number of index to change from original vector v(0-7): ";
        cin>>newIdx;
        
        if(newIdx<0||newIdx>7)
            break;
        
        cout<<"Enter the new value to change: ";
        cin>>newVal;
        
        //newIdx 번째 있던 원래 값
        int oriNum = v.at(newIdx);
        //oriNum-newVal 한 절댓값. newVal 이 더 크면 원래값에 dif 를 더해주고 작으면 원래값에 dif 를 뺴준다.
        int dif = abs(oriNum-newVal);
        //v에 지정된 인덱스(newIdx) 위치에 새로운 값 newVal 입력
        v.at(newIdx)=newVal;
    
        //여러 계산으로 답을 구하는 int 값을 변수로 만들어서 저장해 놓으면 계산을 계속 하지 않아도 되어 연산횟수가 준다.
        segmentTree.at(newIdx+v.size()) = newVal;
        
        /*여기서 쓰는 숫자는 다 예시다
         k 값은 2^k = v.size() 의 k다. 1부터 k까지 2의 제곱으로 (newIdx+v.size()) 를 sesgmentTree 의 idx 값 안에서 나눠주면 9/2=4, 9/4(2^2)=2, 9/8(2^3)=1... 로 계속 나누어 줄 수 있다.
         아무것도 나누지 않은 그 값은 v.at(newIdx)=newVal 이라는 코드로 그냥 9 자체일때 쓸 수 있게 설정했고 그 다음은 나눈값만 한다. 즉, segmentTree[9]은 v.at(newIdx)=newVal 코드로 이미 업데이트 시켰다.
        */
        for(int i=1;i<=k;i++)
        {
            //원래숫자가 newVal 보다 크다면 그 차(=int dif) 를 뺴주면 된다
            if(oriNum>newVal)
            {
                
                segmentTree.at( (newIdx+v.size())/ (pow(2,i) )) = segmentTree.at( (newIdx+v.size()) / (pow(2,i)) ) - dif ;
                //이건 확인차 출력
                //cout<<"oriNum>newVal: "<<segmentTree.at( (newIdx+v.size())/2 ) <<endl<<endl;
            }
            //newVal이 원래숫자 보다 크다면 그 차(=int dif) 를 뺴주면 된다
            else if(oriNum<newVal)
            {
                segmentTree.at( (newIdx+v.size())/ (pow(2,i) )) = segmentTree.at( (newIdx+v.size()) / (pow(2,i)) ) + dif ;
                //이건 확인차 출력
                //cout<<"oriNum>newVal: "<<segmentTree.at( (newIdx+v.size())/ (pow(2,i) )) << endl << endl;
            }
            //newVal 과 원래숫자가 같다면 변화가 없다. 그냥 종료시키면 된다.
            else
            {
                cout<<"No Change!"<<endl;
                break;
            }
        }
        for(int i=0;i<segmentTree.size();i++)
        {
            cout<<"SegmentTree["<<i<<"]: "<<segmentTree.at(i)<<endl;
        }
        
        //계속할건지 어쩔것인지 출력시키기.
        cout<<"Continue?(Press 0 to end. Press 1 to continue): ";
        cin>>endCheck;
        if(endCheck==0)
        {
            cout<<"Thank you for using our program"<<endl;
            check=true;
        }
        else
            check = false;
    }
}

