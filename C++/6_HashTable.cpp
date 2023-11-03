//
//  main.cpp
//  GitUpload
//
//  Created by Junyoung Kim on 2023/11/03.
//


//C++ : HashTable
#include <iostream>
#include <utility>      //STL pair
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    pair<int, vector<int>> p[10];
    int data[20]={88,54,32,67,12, 97,43,22,55,62, 17,73,31,9,11, 34,78,51,29,81};
    for(int j=0;j<20;j++)
    {
        p[j].first = 0;
        int rem = data[j]%10;
        p[rem].second.push_back(data[j]);
    }
    for(int t=0;t<10;t++)
    {
        p[t].first = t;
    }
    for(int i=0;i<10;i++)
    {
        cout<<"Index 번호: "<<i<<endl;
        cout<<"첫번째 페어: "<<p[i].first<<endl;
        //cout<<"Second Pair" : "<<p[i].second.size()<<endl;
        for(int j=0;j<p[i].second.size();j++)
        {
            cout<<"두번째 페어 ["<<j<<"]: "<<p[i].second[j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
