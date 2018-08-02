#include<iostream>

using namespace std;

struct Node
{
    int x;
    Node* next;
    Node() = default;

    Node(int data): x(data), next(nullptr){}
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

Node* reverse_list(Node*head)
{
    if (head == nullptr)
        return nullptr;
    if(head->next == nullptr)
        return head;

    Node* old = head;
    Node* current = head->next;
    head->next = nullptr;
    while(1)
    {
        Node* real_next = current->next;
        current->next = old;
        if (real_next==nullptr)
            return current;
        old = current;
        current = real_next;
    }

}

int main()
{   
    Node* head = get_list_by_cin();
    print_list(head);
    Node* r_head = reverse_list(head);
    print_list(r_head);
}