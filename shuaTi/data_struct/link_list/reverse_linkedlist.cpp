#include<iostream>
#include"single_list.h"

using namespace std;

void reverse_link(Node**head)
{
   if (head == nullptr|| *head == nullptr)
   {
    cout<<"head is null, erro"<<endl;
    return;
   }

   if ((*head)->next == nullptr)
    return;

   if ((*head)->next->next == nullptr)
    return; //only one node, reverse is same as original(if we do not print head)
   

   Node* old = (*head)->next;

   Node* current = old->next;
   old->next = nullptr;

   while(current!=nullptr)
   {
    Node * real_next = current->next;
    current->next = old;
    old = current;
    current = real_next; 
   }
   
   (*head)->next = old;
   
}

void reverse_link(Node*head)
{
   if (head == nullptr)
   {
    cout<<"head is null, erro"<<endl;
    return;
   }

   if (head->next == nullptr)
    return;

   if (head->next->next == nullptr)
    return; //only one node, reverse is same as original(if we do not print head)
   

   Node* old = head->next;

   Node* current = old->next;
   old->next = nullptr;

   while(current!=nullptr)
   {
    Node * real_next = current->next;
    current->next = old;
    old = current;
    current = real_next; 
   }
   
   head->next = old;
   
}
void test()
{
    Node * link_head = create_list_by_cin();

    reverse_link(link_head);

    print_list(link_head);
}


int main()
{
    test();
}