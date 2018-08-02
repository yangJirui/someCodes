#include<iostream>

struct Node
{
    int data;
    Node * next;

    Node() = default;
    Node(int data): data(data), next(nullptr){}
};

void insert_before_element(Node* head, Node *new_node, int element);
void insert_after_element(Node* head, Node* new_node, int element);
void insert_inthe_index(Node* head, Node* new_node, int index);

void delete_specific_element(Node* head, int element);
void delete_after_element(Node* head, int element);

inline Node * create_list_by_cin()
{
    Node *head = new Node();
    int data;
    Node *current = head;
    while(std::cin>>data)
    { 
        Node *new_node = new Node(data);

        current->next = new_node;
        current = current->next;
    }
    return head;
}

inline void print_list(const Node* head)
{
    if (head == nullptr)
    {
        std::cout<<"list is nullptr, erro"<<std::endl;
        return ;
    }
    Node* p = head->next;

    while(p!=nullptr)
    {
        std::cout<<p->data<<std::endl;
        p = p->next;
    }

    std::cout<<"________________"<<std::endl;
}