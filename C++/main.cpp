//
//  main.cpp
//  GitUpload
//
//  Created by Junyoung Kim on 2023/11/03.
//


//C++ : Queue BFS(Not done)

#include <iostream>
#include <cstdlib>      //이거없으면 malloc 안된다.
#include <queue>
#include <vector>
#include <cstring>
/*
 Vector is easy to change the size
 Vector is linkedlist inside. We have v.push_back, v.pop_back, and prev.
 */


//Number of tree 2^n-1(if the trees are all full)        n =15

using namespace std;
class TOPGBugatti
{
public:
    typedef struct Bugatti
    {
        int nodeNum;
        string limEdiNum;
        struct bugatti *left;
        struct bugatti *right;
    }Bugatti;
    
    Bugatti head, tail, *next;
    TOPGBugatti()
    {
        int menu;
        do
        {
            menu = showMenu();
            switch(menu)
            {
                case 1:
                    cout<<"Add"<<endl;
                    insertMenu(&head);
                    break;
                case 2:
                    cout<<"Exit";
                    break;
            }
        }while(menu!=2);
    }
    int showMenu()
    {
        int menu;
        cout<<"======================================================"<<endl;
        cout<<"                 Car Collection Program               "<<endl;
        cout<<"======================================================"<<endl;
        cout<<" 1. Add"<<endl;
        cout<<" 2. Exit"<<endl;
        cout<<"Enter the menu: ";
        cin>>menu;
        return menu;
    }
    void insertMenu(Bugatti *head)
    {
        Bugatti *node, *root;
        node->left = NULL;
        node->right =NULL;
        root->left=NULL;
        root->right = NULL;
        if(root==NULL)
        {
            root = (Bugatti*)malloc(sizeof(Bugatti));
            cout<<"Enter the series number of the car(nodeNum): ";
            cin>>root->nodeNum;
            cout<<"Enter the limited edition serial code(limEdiNum):";
            cin>>root->limEdiNum;
        }
        if(root!=NULL)
        {
            if(node->nodeNum>root->nodeNum)
            {
                if(root->right==NULL)
                {
                    *node = add();
                    root->right = *node;
                }
                if(root->right!=NULL)
                {
                    insertMenu(head);
                }
            }
            if(node->nodeNum<root->nodeNum)
            {
                if(root->left==NULL)
                {
                    *node = add();
                    root->left = *node;
                }
                if(node->left!=NULL)
                {
                    insertMenu(head);
                }
            }
        }
    }
    Bugatti add()
    {
        Bugatti *node;
        node = (Bugatti*)malloc(sizeof(Bugatti));
        cout<<"Enter the series number of the car(nodeNum): ";
        cin>>node->nodeNum;
        cout<<"Enter the limited edition serial code(limEdiNum):";
        cin>>node->limEdiNum;
        return *node;
    }
};
int main()
{
    
}
