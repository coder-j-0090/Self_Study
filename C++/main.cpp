//
//  main.cpp
//  GitUpload
//
//  Created by Junyoung Kim on 2023/11/03.
//


//C++ : NetworkFlow(Not done)
//
//  main.cpp
//  NetworkFlow
//
//  Created by Junyoung Kim on 2023/05/22.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n = 6, result=0;
int c[100][100], f[100][100], d[100];
vector <int> a[100];
void maxFlow(int start, int end)
{
    while(1)
    {
        fill(d, d+100, -1);
        queue<int>q;
        q.push(start);
        while(!q.empty())
        {
            int x = q.front()
            cout<<"q: "<<x<<endl<<endl;
            q.pop();
            for(int i=0;i<a[x].size();i++)
            {
                int y = a[x][i];
                cout<<"y(=a[x][i]): "<<y<<endl;
                
                
                if(c[x][y] - f[x][y]>0 && d[y]==-1)
                {
                    q.push(y);
                    d[y]=x;
                    if(y==end)
                        break;
                }
            }
            
            cout<<endl;
            for(int i=1;i<7;i++)
            {
                cout<<"d["<<i<<"] 배열 확인하기: "<<d[i]<<endl;
            }
            cout<<endl;
            
        }
        
        
        
        cout<<"d[end]가 몇이냐?: "<<d[end]<<endl<<endl;
        
        
        if(d[end]==-1)
            break;
        
        int flow = 1000000;
        for(int i=end;i!=start;i=d[i])
        {
            cout<<"i: "<<i<<endl;
            
            cout<<"min 전 flow : "<<flow<<endl;
            cout<<"min 찾기(전 c): "<<c[d[i]][i]<<endl;
            cout<<"min 찾기(전 f): "<<f[d[i]][i]<<endl;
            cout<<"min 전 c-f : "<<c[d[i]][i]-f[d[i]][i]<<endl;
            cout<<"min 전 flow 찾기: "<<flow<<endl<<endl;
            
            flow = min(flow, c[d[i]][i] - f[d[i]][i]);
            
            
            cout<<"min 찾기(c): "<<c[d[i]][i]<<endl;
            cout<<"min 찾기(f): "<<f[d[i]][i]<<endl;
            cout<<"min c-f : "<<c[d[i]][i]-f[d[i]][i]<<endl;
            cout<<"min flow 찾기: "<<flow<<endl<<endl;
            
            
        }
        
        
        for(int i=end;i!=start;i=d[i])
        {
            cout<<"Weird For : "<<i<<endl;
        }
        cout<<endl;
        
        
        for(int i=end;i!=start;i=d[i])
        {
            cout<<"i2: "<<i<<endl;
            
            f[d[i]][i] += flow;
            cout<<"Positive flow : "<<f[d[i]][i]<<endl;
            f[i][d[i]] -= flow;
            cout<<"Negative flow : "<<f[i][d[i]]<<endl<<endl;
        }
        result += flow;
        
        cout<<endl<<"Result Flow: "<<flow<<endl<<endl<<endl;
    }
}
int main()
{
    a[1].push_back(2);
    a[2].push_back(1);
    c[1][2] = 12;
    
    a[1].push_back(4);
    a[4].push_back(1);
    c[1][4] = 11;
    
    a[2].push_back(3);
    a[3].push_back(2);
    c[2][3] = 6;
    
    a[2].push_back(4);
    a[4].push_back(2);
    c[2][4]=3;
    
    a[2].push_back(5);
    a[5].push_back(2);
    c[2][5] = 5;
    
    a[2].push_back(6);
    a[6].push_back(2);
    c[2][6] = 9;
    
    a[3].push_back(6);
    a[6].push_back(3);
    c[3][6] = 8;
    
    a[4].push_back(5);
    a[5].push_back(4);
    c[4][5] = 9;
    
    a[5].push_back(3);
    a[3].push_back(5);
    c[5][3] = 3;
    
    a[5].push_back(6);
    a[6].push_back(5);
    c[5][6] = 4;
    
    maxFlow(1,6);
    cout<<"After Method Result: "<<result<<endl;
}
