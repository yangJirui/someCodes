# include<iostream>
# include"single_list.h"

using namespace std;



// 对于一个有序递增链表，删除其重复元素


void delete_duplicate_node(Node** head)
{
    if (head == nullptr || *head == nullptr || (*head)->next == nullptr)
        return;


    Node * old = *head;
    Node * current = (*head)->next;


    while(current !=nullptr)
    {
       if(old->x == current->x)
       {
        old->next = current->next;
        Node* tmp = current;
        current = current->next;
        delete tmp;
       }
       else
       {
           old = current;
           current= current->next;
       }
    }
}


int main()
{
    Node* head = create_list_by_cin();

    delete_duplicate_node(&head);

    print_list(head);
}