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
    vector<int> v = {4,2,8,4,3,2,1,7};
    //num is v.size(), segmentTree needs 2*2^k vector
    int num=0, k=0;
    
    while(num<v.size())
    {
        num = pow(2,k);
        k++;
    }
    
    //segmentTree needs num*2.
    vector<int> segmentTree (num*2);
    int j = 0 ;
    for(int i=num;i<num*2;i++)
    {
        segmentTree.at(i) = v.at(j);
        j++;
    }
    //Dump 0.
    //If vector v is 8, then do *2 and get 16.
    for(int i=segmentTree.size()-1;i>0;i--)
    {
        //Change the value of i/2 in segmentTree as a sum of segmentTree i/2 and i.
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
        
        int oriNum = v.at(newIdx);
        int dif = abs(oriNum-newVal);
        v.at(newIdx)=newVal;
    
        segmentTree.at(newIdx+v.size()) = newVal;
        
        /*여기서 쓰는 숫자는 다 예시다
         k 값은 2^k = v.size() 의 k다. 1부터 k까지 2의 제곱으로 (newIdx+v.size()) 를 sesgmentTree 의 idx 값 안에서 나눠주면 9/2=4, 9/4(2^2)=2, 9/8(2^3)=1... 로 계속 나누어 줄 수 있다.
         아무것도 나누지 않은 그 값은 v.at(newIdx)=newVal 이라는 코드로 그냥 9 자체일때 쓸 수 있게 설정했고 그 다음은 나눈값만 한다. 즉, segmentTree[9]은 v.at(newIdx)=newVal 코드로 이미 업데이트 시켰다.
        */
        for(int i=1;i<=k;i++)
        {
            if(oriNum>newVal)
            {
                
                segmentTree.at( (newIdx+v.size())/ (pow(2,i) )) = segmentTree.at( (newIdx+v.size()) / (pow(2,i)) ) - dif ;
                //cout<<"oriNum>newVal: "<<segmentTree.at( (newIdx+v.size())/2 ) <<endl<<endl;
            }
            else if(oriNum<newVal)
            {
                segmentTree.at( (newIdx+v.size())/ (pow(2,i) )) = segmentTree.at( (newIdx+v.size()) / (pow(2,i)) ) + dif ;
                //cout<<"oriNum>newVal: "<<segmentTree.at( (newIdx+v.size())/ (pow(2,i) )) << endl << endl;
            }
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

