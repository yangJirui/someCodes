#include<iostream>
using namespace std;


struct Node
{
    int x;
    Node* next;
    Node() = default;

    Node(int data): x(data), next(nullptr){}
    Node(int xx, Node* nn):x(xx), next(nn){}
};

Node * get_list_by_cin()
{
    int data;
    Node* head = nullptr;
    if(cin>>data)
        head = new Node(data);
    else
        return nullptr;
    Node* p= head;
    while(cin>>data)
    {
        p->next = new Node(data);
        p = p->next;
    }
    return head;
}

void print_list(Node* head)
{
    if(head==nullptr)
        return ;
    Node* p = head;
    while(p!=nullptr)
    {
        cout<<p->x<<" ";
        p = p->next;
    }
    cout<<endl;
    cout<<"*****"<<endl;
}

Node* merge(Node* head1, Node*head2)
{
    if(head1==nullptr)
        return head2;
    if(head2==nullptr)
        return head1;

    Node *pmerge = nullptr;

    if(head1->x<head2->x)
    {
        pmerge = head1;
        pmerge->next = merge(head1->next, head2);
    }
    else
    {
        pmerge = head2;
        pmerge->next = merge(head1, head2->next);
    }

    return pmerge;
}


int main()
{   
    cout<<"input the list1"<<endl;
    Node* head1 = get_list_by_cin();
    cout<<"input the list2"<<endl;
    // char t;
    // cin>>t;
    Node* head2 = new Node(2, new Node(4, new Node(6, new Node(8))));

    Node* merged = merge(head1, head2);

    print_list(merged);
}