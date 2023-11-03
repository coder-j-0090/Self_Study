//
//  main.cpp
//  GitUpload
//
//  Created by Junyoung Kim on 2023/11/03.
//


//C++ : UnlimitedLinkedList


#include <iostream>
#include <cstring>
using namespace std;
typedef struct PocketMonster
{
    char name[10];
    int age;
    struct PocketMonster *next;
}PocketMonster;
int showMenu();
void insertMenu(PocketMonster *head);
void printMenu(PocketMonster *head);
void searchMenu(PocketMonster *head);
void deleteMenu(PocketMonster *head);
int main()
{
    PocketMonster head, tail;
    head.next = &tail;
    tail.next = NULL;
    int menuNum;
    do
    {
        menuNum = showMenu();
        switch(menuNum)
        {
            case 1:
                cout<<"Add"<<endl;
                insertMenu(&head);
                break;
            case 2:
                cout<<"Print"<<endl;
                printMenu(&head);
                break;
            case 3:
                cout<<"Search"<<endl;
                searchMenu(&head);
                break;
            case 4:
                cout<<"Delete"<<endl;
                deleteMenu(&head);
                break;
            case 5:
                cout<<"Exit"<<endl;
                break;
        }
    }while(menuNum!=5);
}
int showMenu()
{
    int menu;
    cout<<"=================================================="<<endl;
    cout<<"                 Membership Program               "<<endl;
    cout<<"=================================================="<<endl;
    cout<<" 1. Add"<<endl;
    cout<<" 2. Print"<<endl;
    cout<<" 3. Search"<<endl;
    cout<<" 4. Delete"<<endl;
    cout<<" 5. Exit"<<endl;
    cout<<"Enter Number: ";
    cin>>menu;
    
    return menu;
}
void insertMenu(PocketMonster *head)
{
    PocketMonster *node;
    node = (PocketMonster*)malloc(sizeof(PocketMonster));
    cout<<"Name: ";
    cin>>node->name;
    cout<<"Age: ";
    cin>>node->age;
    cout<<endl;
    node->next = head->next;
    head->next= node;
}
void printMenu(PocketMonster *head)
{
    PocketMonster *node;
    node = head->next;
    while(node->next!=NULL)
    {
        cout<<"Printed Name : "<<node->name<<endl<<"Printed Age : "<<node->age<<endl;
        node = node->next;
    }
}
void searchMenu(PocketMonster *head)
{
    char keyword[20];
    cout<<"Searching Keyword(Name): ";
    cin>>keyword;
    PocketMonster *node;
    node = head;
    while(node->next != NULL)
    {
        if(strcmp(node->name,keyword)==0)
        {
            cout<<"Match with "<<node->name<<" and the age is "<<node->age<<"."<<endl;
        }
        node = node->next;
    }
}
void deleteMenu(PocketMonster *head)
{
    char pocketDeleteName[10];
    cout<<"Enter the name of PocketMon you want to delete: ";
    cin>>pocketDeleteName;
    PocketMonster *node, tail;
    tail.next=NULL;
    node = head;
    while(node->next!=NULL)
    {
        if(strcmp(node->next->name,pocketDeleteName)==0)        //node는 이름이 없다. 그래서 한 특정 노드를 지정할 수 없지만, 그 노드의 전 노드를 건들 수 는 있다.
        {
            node->next=node->next->next;
        }
        node = node->next;
    }
    cout<<"It is deleted"<<endl;
    printMenu(head);
    //구조적 특성. head 가 있고 Node->next->name. (node->next)->name 으로 쳐야한다. 해석에 도움을 위해서.
}
