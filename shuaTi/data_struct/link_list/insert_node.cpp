#include<iostream>
#include"single_list.h"

using namespace std;


/*
NOTE:
when insert node, can only insert once, since the parameter new_node is fixed.
*/
void insert_before_element(Node* head, Node *new_node, int element)
{
    /**

    */
    if (head->next == nullptr)
    {
        cout<<"list head is nullptr, erro"<<endl;
        return;
    }
    Node * old = nullptr;
    Node * current = head;
    while(current->next!= nullptr)
    {

        old = current;
        current = current->next;
        if (current->data == element)
        {
            new_node->next = current;
            old->next = new_node;
            return ;
        }
    }
    
    cout<< "not find element in the list"<<endl;
}

void insert_after_element(Node* head, Node* new_node, int element)
{
    if (head==nullptr)
    {
        cout<<"list head is nullptr, erro"<<endl;
        return;
    }
    Node * current = head->next;

    while(current != nullptr)
    {
        if (current->data == element)
        {
            new_node->next = current->next;
            current->next = new_node;
            return ;
        }
        current = current->next;
    }

    cout<<"not find element in the list"<<endl;
}

void insert_inthe_index(Node* head, Node* new_node, int index)
{
    /*
    after insertation, the location of new_node is index;
    e.g. index = 1, the new_node location in the list is 1;
    index range: [1, inf)
    */
    
    if (index<=0) 
    {
        cout<<"index<=0, erro"<<endl;
        return;
    }
    int count = 0;
    Node *old;
    Node * current= head;
    
    while(current->next != nullptr)
    {
        old = current;
        current = current->next;
        count ++;

        if (count == index)
        {
            old->next = new_node;
            new_node->next = current;
            return ;
        }
    }
    cout<<"index is larger than the length of list"<<endl;

}