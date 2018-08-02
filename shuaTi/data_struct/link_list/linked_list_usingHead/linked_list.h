#include<iostream>
using namespace std;
struct Node
{
    int x;
    Node * next;

    Node() = default;
    Node(int data): x(data), next(nullptr) {}
    Node(int data, Node* np): x(data), next(np) {}
};

inline void print_list(Node* head)
{
    if (head == nullptr)
    {
        cout<<"head is nullptr, erro"<<endl;
        return; 
    }

    Node *p = head;

    while(p!= nullptr)
    {
        cout<<p->x<<endl;
        p = p->next;
    }
    cout<<"____________"<<endl;
}

inline void create_list_bycin(Node **head)
{
    if (head == nullptr)
    {
        cout<<"the address of head is nullptr, erro"<<endl;
        return ;
    }
    
    int data;
    // cout<<"*head:: "<<*head<<endl;
    if (*head == nullptr)
    {   
        // cout<<"head is null, cin the fist num"<<endl;
        if(cin>>data)
           *head = new Node(data);
        // cout<<"(("<<endl;
        else return;
    }

    Node *p = *head;
    // cout<<"p::"<<p<<endl;
    while(cin>>data)
    {
         p->next = new Node(data);
         p = p->next;
    }

}