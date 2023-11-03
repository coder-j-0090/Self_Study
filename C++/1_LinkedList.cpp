//
//  main.cpp
//  GitUpload
//
//  Created by Junyoung Kim on 2023/11/03.
//


//C++ : LinkedList


#include <iostream>
#include <cstring>
using namespace std;
typedef struct PocketMonster
{
    char name[10];
    int age;
    struct PocketMonster *next;
}PocketMonster;
int main()
{
    PocketMonster head, tail, *node;
    head.next = &tail;
    tail.next = NULL;
    
    int numOfNode;
    cout<<"Number of Node: ";
    cin>>numOfNode;
    node = &head;
    for(int i=0;i<numOfNode;i++)
    {
        node = (PocketMonster*)malloc(sizeof(PocketMonster));
        cout<<"Name: ";
        cin>>node->name;
        cout<<"Age: ";
        cin>>node->age;
        node->next = head.next;
        head.next = node;
    }
    cout<<endl<<endl;
    
    node = head.next;
    while(node->next!=NULL)
    {
        if(strcmp("b",node->name)==0)
        {
            node = node->next;
        }
        cout<<"Result Name: "<<node->name<<endl<<"Result Age: "<<node->age<<endl<<endl;
        node = node->next;
    }
}

