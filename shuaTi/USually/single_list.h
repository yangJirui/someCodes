#include<iostream>

struct Node
{
    int x;
    Node * next;

    Node() = default;
    Node(int data): x(data), next(nullptr){}
};

inline Node * create_list_by_cin()
{
    // Node *head = new Node();
    int data;
    std::cin>>data;
    Node *head = new Node(data);
    Node *current = head;
    while(std::cin>>data)
    { 
        Node *new_node = new Node(data);

        current->next = new_node;
        current = current->next;
    }
    return head;
}

inline void print_list(Node* head) 
{
    if (head == nullptr)
    {
        std::cout<<"list is nullptr, erro"<<std::endl;
        return ;
    }
    Node* p = head;

    while(p!=nullptr)
    {
        std::cout<<p->x<<" ";
        p = p->next;
    }
    
    std::cout<<std::endl<<"________________"<<std::endl;
}
