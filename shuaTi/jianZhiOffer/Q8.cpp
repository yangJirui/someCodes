#include<iostream>

using namespace std;

struct Node
{
    int x;
    Node * left;
    Node * right;
    Node * father;

    Node() = default;
    Node(int data): x(data), left(nullptr), right(nullptr), father(nullptr) {}

    Node(int data, Node*l, Node* r, Node* f): x(data), left(l), right(r), father(f) {}
};


Node * find_next(Node* the_node)
{
    if(the_node == nullptr)
        return nullptr;

    if(the_node->right != nullptr)
    {
        Node * p = the_node->right;
        while(p->left!=nullptr)
            p = p->left;
        
        return p;
    }
    else
    {   

        Node* the_father = the_node->father;
        if (the_father!= nullptr)
        {
            if (the_father->left == the_node)
               return the_father;
        
            else
            {
                Node * p = the_father;
                while(p->father!= nullptr)
                {    
                    if (p == p->father->left)
                    {
                        return p->father;
                    }
                    p = p->father;
                }
                return nullptr;
            }
        }
        else return nullptr;
    }
}

void test1()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    Node* node9 = new Node(9);

    node1->left = node2; node1->right = node3;
    node2->left = node4; node2->right = node5; 
    node5->left = node6; node5->right = node7; 

    node3->left = node8; node3->right = node9;
    node2->father = node1;
    node3-> father = node1;node4->father=node2;node5->father = node2;
    node6-> father = node5; node7->father=node5; node8->father=node3; node9->father=node3;


    Node* result = find_next(node5);

    if (result == nullptr)
        {
            cout<<"result is nullptr, erro"<<endl;
            return;
        }
    cout<<result->x<<endl;
    cout<<"******"<<endl;
}
void test2()
{
    Node * node1 = new Node(1); 
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    node1->left = node2; node2->left=node3;
    node2->father=node1; node3->father = node2;
    Node* result = find_next(node3);

    if (result == nullptr)
        {
            cout<<"result is nullptr, erro"<<endl;
            return;
        }
    cout<<result->x<<endl;
    cout<<"******"<<endl;

}

void test3()
{
    Node * node1 = new Node(1); 
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    node1->right = node2; node2->right=node3;
    node2->father=node1; node3->father = node2;
    Node* result = find_next(node1);

    if (result == nullptr)
        {
            cout<<"result is nullptr, erro"<<endl;
            return;
        }
    cout<<result->x<<endl;
    cout<<"******"<<endl;

}
int main()
{
    // test1();
    // test2();
    test3();
}
