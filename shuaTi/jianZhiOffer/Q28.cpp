#include<iostream>
using namespace std;

struct Node
{
    int x;
    Node* left ;
    Node *right;
    Node() = default;

    Node(int data):x(data), left(nullptr), right(nullptr){}

    Node(int data, Node*l, Node* r): x(data), left(l), right(r){}

};

bool is_reflect(Node* root1, Node* root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;

    if(root1 == nullptr || root2 == nullptr)
        return false;

    if(root1->x != root2->x)
        return false;

    return is_reflect(root1->left, root2->right)&&is_reflect(root1->right, root2->left);
}

Node* make_tree()
{
    // return new Node(8, new Node(6, new Node(5), new Node(7)), 
    //                    new Node(10, new Node(9), new Node(11)));

    return new Node(8, new Node(7, new Node(6), nullptr), nullptr);

}
