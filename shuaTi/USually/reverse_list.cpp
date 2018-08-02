#include<iostream>
#include"single_list.h"

using namespace std;


void reverse(Node** head)
{
    if(head == nullptr || (*head) == nullptr || (*head)->next==nullptr)

        return;

    Node* old = *head;
    Node* current = (*head)->next;
    
    old->next = nullptr;

    while(current !=nullptr)
    {
        Node* tmp = current->next;
        current->next = old;

        old = current;
        current = tmp;
    }

    *head = old;
}

int main()
{
    Node* head = create_list_by_cin();
    print_list(head);

    reverse(&head);

    print_list(head);

}