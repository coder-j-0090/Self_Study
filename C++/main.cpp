//
//  main.cpp
//  GitUpload
//
//  Created by Junyoung Kim on 2023/11/03.
//


//C++ : B-Tree(Not done)
//
//  main.cpp
//  B-Tree
//
//  Created by Junyoung Kim on 2023/05/22.
//
#include <iostream>
using namespace std;
typedef struct Node
{
    int key1;
    int key2;
    
    struct Node *left;
    struct Node *right;
    struct Node *mid;
}Node;
void insert(Node *Node, int num);
void print(Node *node);
int main()
{
    Node Btree;
    Btree.key1 = 30;
    Btree.key2 = 60;
    
    
    Node *node;
    node = (Node*)malloc(sizeof(Node));
    node->key1 = 10;
    node->key2 = 20;
    node->left = NULL;
    node->right = NULL;
    node->mid = NULL;
    
    Btree.left = node;
    
    Node *node2;
    node2 = (Node*)malloc(sizeof(Node));
    node2->key1 = 50;
    node2->key2 = 0;
    node2->left = NULL;
    node2->right = NULL;
    node2->mid = NULL;
    
    Btree.mid = node2;
    
    Node *node3;
    node3 = (Node*)malloc(sizeof(Node));
    node3->key1 = 80;
    node3->key2 = 0;
    node3->left = NULL;
    node3->right = NULL;
    node3->mid = NULL;
    
    Btree.right = node3;
    
    print(&Btree);
    cout<<"Line Changing"<<endl;
    insert(&Btree, 55);
    print(&Btree);
}
void insert(Node *node, int num)
{
    if(node->left==NULL&&node->mid==NULL&&node->right==NULL)
    {
        if(node->key1==0)
        {
            node->key1 = num;
        }
        else if(node->key2==0)
        {
            node->key2 = num;
        }
        else
        {
            //TODO: 비교해서 왼(작은거), 가운데(중간거), 오(큰거) 중 하나에 끼워넣어야된다. 그다음에 가운데 걸 위로 보내서 위에다가 가져다 붙인다. 위에꼐 3개가 되면 계속 위로 올려서 balance tree가 되게한다.
        }
    }
    else
    {
        if(num<node->key1)
        {
            insert(node->left,num);
        }
        else if(num<node->key2)
        {
            insert(node->mid,num);
        }
        else
        {
            insert(node->right,num);
        }
    }
}
void print(Node *node)
{
    if(node->key1!=0)
    {
        cout<<node->key1<<endl;
    }
    if(node->key2!=0)
    {
        cout<<node->key2<<endl;
    }
    if(node->left!=NULL)
    {
        print(node->left);
    }
    if(node->mid!=NULL)
    {
        print(node->mid);
    }
    if(node->right!=NULL)
    {
        print(node->right);
    }
}
