#include<iostream>
#include"single_list.h"

using namespace std;


void delete_specific_element(Node* head, int element)
{ 
    if (head == nullptr) 
    {
        cout<<"list head is nullptr, erro"<<endl;
        return;
    }
    Node * old;
    Node * current = head;
    
    bool flag = false;
    while(current->next != nullptr)
    {
        
        
        old = current;
        current = current->next;
        
        if (current->data == element)
        {
           old->next = current->next;
           delete(current);
           current = old;
           flag = true;
        }
    }
    if (!flag) cout<<"element not in the list"<<endl;

}

void delete_after_element(Node* head, int element)
{
    if (head == nullptr)
    {
        cout<<"list head is nullptr, erro"<<endl;
        return;
    }
    Node * current = head->next;

    while(current != nullptr)
    {
        if (current->data == element)
        {
            if (current->next == nullptr)
            {
                cout<<"after this element, there is no data"<<endl;
                return;
            }
            else
            {
                Node* next_node = current->next;
                current->next = next_node->next;
                delete(next_node);
            }
        } 

        current = current->next;
    }
}