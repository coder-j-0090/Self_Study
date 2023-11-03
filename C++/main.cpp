//
//  main.cpp
//  GitUpload
//
//  Created by Junyoung Kim on 2023/11/03.
//


//C++ : Sliding Door
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //Put numbers in vector
    vector<int>v = {4, -45, 23, 5, 11, -9, 7, 12, -2, 66, 834, -54, 33, 143, 667, -324, 611, 850, -441, 2};
    //Make vectors save the sums.
    vector<int>total = {0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0};
    total[0]=v[0];
    for(int i=1;i<20;i++)
    {
        total[i]=total[i-1]+v[i];
    }
    int start=0, sum=0, end=0, max=0;
    for(int i=0;i<v.size();i++)
    {
        cout<<"Original Start: "<<start<<endl;
        cout<<"Original End : "<<end<<endl;
        cout<<"Original Sum : "<<sum<<endl;
        cout<<"Original Max: "<<max<<endl<<endl;
        
        start = v[i];
        end = v[i+2];
        if(i+2==v.size())
            break;
        sum = total[i+2]-total[i-1];
        if(sum>max)
        {
            max=sum;
        }
        
        //검토
        cout<<"Start: "<<start<<endl;
        cout<<"End : "<<end<<endl;
        cout<<"Sum : "<<sum<<endl;
        cout<<"Max: "<<max<<endl<<endl;
    }
}



//3 Doors
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //숫자들이 들어있는 벡터 생성(최대 부분합 찾기위해서)
    vector<int>v = {4, -45, 23, 5, 11, -9, 7, 12, -2, 66, 834, -54, 33, 143, 667, -324, 611, 850, -441, 2};
    //숫자들을 다 더해논 합을 저장할 배열.
    vector<int>total = {0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0};
    //맨 처음은 숫자와 합이 같다. 더할 숫자 자체도 없고
    total[0]=v[0];
    //그 다음에는 다 더해논거에 새로운 숫자 하나 더하는 방법으로 v.size() 만큼 for문으로 반복
    for(int i=1;i<20;i++)
    {
        total[i]=total[i-1]+v[i];
    }
    //시작, 끝, 합, 그리고 합의 최댓값 구하기
    int start=0, sum=0, end=0, max=0;
    //v.size()만큼 돌면서 숫자 구하기
    for(int i=0;i<v.size()-2;i++)
    {
        //검토
        cout<<"Original Start: "<<start<<endl;
        cout<<"Original End : "<<end<<endl;
        cout<<"Original Sum : "<<sum<<endl;
        cout<<"Original Max: "<<max<<endl<<endl;
        
        //시작점 v[i].
        start = v[i];
        //3칸씩 검열할거라 i+2(첫칸으로 부터 두칸 뒤)
        end = v[i+2];
        //새로 start 와 end 값을 받은 후를 비교해보자
        
// for(int i=0;i<v.size();i++) 로 for 문을 써두고 밑에 두줄을 써도 되지만
//        if(i+2==v.size())
//            break;
        //그냥 v.size()-2 를 해줘도 된다. 이건 인터넷 보다가...
        
        
        //3 수의 합은 마지막 위치의 토탈값에서 시작점 전에 칸의 값을 빼줘야 한다.
        sum = total[i+2]-total[i-1];
        //합이 최댓값보다 크면 그 합이 최댓값이 된다.
        if(sum>max)
        {
            max=sum;
        }
        
        //검토
        cout<<"Start: "<<start<<endl;
        cout<<"End : "<<end<<endl;
        cout<<"Sum : "<<sum<<endl;
        cout<<"Max: "<<max<<endl<<endl;
    }
}
 */

//Number of doors can be chosen
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int>v = {4, -45, 23, 5, 11, -9, 7, 12, -2, 66, 834, -54, 33, 143, 667, -324, 611, 850, -441, 2};
    vector<int>total = {0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0};
    
    total[0]=v[0];
    for(int i=1;i<20;i++)
    {
        total[i]=total[i-1]+v[i];
    }
    
    int start=0, sum=0, end=0, max=0, numOfDoor;
    //door 의 갯수는 몇개인지 내가 입력하는 칸이 된다.
    cout<<"Enter the number of Door: ";
    cin>>numOfDoor;
    
    
    for(int i=0;i<v.size()-(numOfDoor-1);i++)
    {
        cout<<"Original Start: "<<start<<endl;
        cout<<"Original End : "<<end<<endl;
        cout<<"Original Sum : "<<sum<<endl;
        cout<<"Original Max: "<<max<<endl<<endl;
        
        start = v[i];
        end = v[i+(numOfDoor-1)];
        sum = total[i+(numOfDoor-1)]-total[i-1];
        if(sum>max)
        {
            max=sum;
        }
        
        cout<<"Start: "<<start<<endl;
        cout<<"End : "<<end<<endl;
        cout<<"Sum : "<<sum<<endl;
        cout<<"Max: "<<max<<endl<<endl;
    }
}
 */

