#include<iostream>
#include"linked_list.h"
#include<stack>

using namespace std;

void add_to_tail(Node** head, Node * new_node);

void delete_specific_node(Node** head, int element);

void delete_index_node(Node** head, int index);

void insert_before_element(Node** head, Node* new_node, int element);

void insert_after_element(Node**head, Node* new_node, int element);

void insert_in_the_index(Node** head, Node* new_node, int index);

void reverse_list(Node**head);

void reverse_out_by_stack(Node * head);

void reverse_out_by_recurrent(Node *head);


void add_to_tail(Node** head, Node *new_node)
{
    if (head == nullptr)
    {
        cout<<"the address of head pointer is nullptr, erro"<<endl;
        return;
    }

    if (*head == nullptr)
    {
        *head = new_node;
    }
    else
    {
       Node * p = *head;
       while(p->next!= nullptr)
       {
        p = p->next;
       }
       p->next = new_node;
    }
}

void delete_specific_node(Node** head, int element)
{
    if (head == nullptr)
    {
        cout<<"the address of head pointer is nullptr, erro"<<endl;
        return ;
    }

    if (*head == nullptr)
    {
        cout<<"the len of list is nullptr"<<endl;
        return;
    }
    
    while((*head)->x == element)
    {    
         Node* original_head = *head;
        *head = (*head)->next;
         delete original_head;
         if(*head == nullptr)
            return;
    }
    
    Node * old;
    Node * current = *head;
    bool flag = false;
    while(current->next != nullptr)
    {
        old = current;
        current = current->next;
        if (current->x == element)
        {
            old->next = current->next;
            delete current;
            current= old;
            flag = true;
        }
    }
    if (!flag) cout<<"the element do not exsit in the list"<<endl;
}


void delete_index_node(Node** head, int index)
{

    if (head == nullptr|| *head == nullptr)
    {
        cout<<"the address of head pointer is nullptr|| the len of list is 0"<<endl;
        return;
    }
    if(index<0) return;
    
    if (index == 0)
    {
       Node* original_head = *head;
       *head = (*head)->next;
       delete original_head;
       return;
    }

    int count = 0;

    Node * old;
    Node * current = *head;
    while(current->next!=nullptr)
    {
        old = current;
        current = current->next;
        count ++;
        if (count == index)
        {   
            old->next = current->next;
            delete current;
            current = old;
        }
    }
    if(index >count) cout<<"index larger than the max index of list"<<endl;
}

void insert_after_element(Node** head, Node * new_node, int element)
{
    if(head == nullptr|| *head==nullptr)
        return;

    Node * current = *head;
    
    while(current!= nullptr)
    {
        if (current->x == element)
        {
            new_node->next = current->next;
            current->next = new_node;
            return ;
        }
        current = current->next;
    }
    cout<<"element not exsit in the list"<<endl;
}

void insert_before_element(Node** head, Node* new_node, int element)
{
    if (head == nullptr|| *head == nullptr)
    {
        return ;
    }
    if((*head)->x == element)
    {
        new_node->next = *head;
        *head = new_node;
        return ;
    }

    Node * old;
    Node *current = *head;
    while(current->next != nullptr)
    {   
        old = current;
        current = current->next;
        if (current->x == element)
        {
            new_node->next = current;
            old->next = new_node;
            return ;
        }
    }
    cout<<"not find element in the list"<<endl;
}

void insert_in_the_index(Node **head, Node* new_node, int index)
{
   
   if(head == nullptr|| index<0)
   {
    return ;
   }

   if(*head == nullptr && index >0)
    {
        cout<<"index larger than max_index"<<endl;
        return;
    }  
   if(index == 0)
   {
    new_node->next = *head;
    *head = new_node;
    return;
   }
   
   Node * old;
   Node * current = *head;
   int count = 0;

   while(current->next != nullptr)
   {
      old = current;
      current = current->next;
      count ++ ;
      if (count== index)
      {
        new_node->next = current;
        old->next = new_node;
        return;
      }
   }
   if(index>count ) cout<<"index larger than max index"<<endl;
}

void reverse_list(Node** head)
{
    if(head == nullptr|| *head==nullptr|| (*head)->next == nullptr)
    {
        return;
        // if only one node, after reversation, is same as original list
    }

    Node *old= *head;
    Node *current = (*head)->next;
    
    old->next = nullptr;
    cout<<"current"<<current<<endl;
    while(current != nullptr)
    {
        Node * real_next = current->next;
        current->next = old;
        
        old = current;
        current = real_next;
    }
    *head = old;
}

void reverse_out_by_stack(Node * head)
{
   
   if (head == nullptr)
   {
    return ;
   }
   stack<Node* > node_stack;
   

   Node * p = head;
  
   while(p!=nullptr)
   {
    node_stack.push(p);
    p = p->next;
   }

   while(!node_stack.empty())
   {
    Node * top = node_stack.top();
    node_stack.pop();
    cout<<top->x<<endl;
    // delete top; do not add this;
   }
}

void reverse_out_by_recurrent(Node * head)
{
    if(head == nullptr)
        return ;

    reverse_out_by_recurrent(head->next);

    cout<<head->x<<endl;
}

int main()
{
    Node* list_head = nullptr;

    create_list_bycin(&list_head);
    cout<<"create_over"<<endl;
    print_list(list_head);

    // add_to_tail(&list_head, new Node(999));
    // delete_specific_node(&list_head, 2);
    // delete_index_node(&list_head, 2);
    // insert_after_element(&list_head, new Node(999), 2);
    // insert_before_element(&list_head, new Node(999), 2);
    // insert_in_the_index(&list_head, new Node(999), 2);
    // reverse_list(&list_head);

    // reverse_out_by_stack(list_head);
    reverse_out_by_recurrent(list_head);
    cout<<"changed over"<<endl;
    print_list(list_head);
}
