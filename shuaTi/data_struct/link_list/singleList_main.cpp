#include<iostream>
#include"single_list.h"

using namespace std;

int main()
{
    Node * list_head = create_list_by_cin();
    
    print_list(list_head);
 
    
    /*
    when test, list is [1, 2, 3]
    */

    // // test insert_node_before_element;
    // insert_before_element(list_head, new Node(999), 9); // test(1, 3, 9)
    // print_list(list_head);

    // test insert_after_element;
    // insert_after_element(list_head, new Node(999), 3); // test(1, 3, 9)
    // print_list(list_head);

    // //test insert_inthe_index
    // insert_inthe_index(list_head, new Node(999), 0); //test(0, 1, 3, 4, 5)
    // print_list(list_head);


    //test delete_specific_element
    // delete_specific_element(list_head, 3);
    // print_list(list_head);


    //test delete_after_element
    delete_after_element(list_head, 3);
    print_list(list_head);
}