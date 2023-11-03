//
//  main.cpp
//  GitUpload
//
//  Created by Junyoung Kim on 2023/11/03.
//


//C++ : Stack
#include <iostream>
#include <cstring>
using namespace std;
class TryStack
{
public:
    typedef struct regInt
    {
        int num;
        struct regInt *next;
    }regInt;
    
    regInt head, tail, *node;
    TryStack()      
    {
        head.next = &tail;
        tail.next = NULL;
    }
    
    void push(int remainder)
    {
        regInt *node;
        node = (regInt*)malloc(sizeof(regInt));
        node->num = remainder;
        node->next = head.next;
        head.next = node;
    }
    
    int top()
    {
        return head.next->num;
    }
    
    void pop()
    {
        //cout<<"The last added value is "<<head.next<<" and it will be removed."<<endl;;
        head.next = head.next->next;
    }
    
    bool empty()
    {
        if(head.next==&tail)            //if((head.next)->next == NULL)
            return true;
        else
            return false;
    }
};
int main()
{
    TryStack ts;
    cout<<"Enter number: ";
    int num;
    cin>>num;
    while(num>0)
    {
        ts.push(num%2);
        num = num/2;
    }
    while(!ts.empty())
    {
        cout<<ts.top();
        ts.pop();
    }
    return 0;
}
