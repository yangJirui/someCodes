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

bool is_balanced(Node* root, int* depth)
{
    if(root == nullptr)
    {
        *depth=0;
        return true;
    }

    int left, right;
    if(is_balanced(root->left, &left) && is_balanced(root->right, &right))
    {

        int diff = *left - *right;

        if(diff<=1&& diff>=-1)
        {

            *depth = *left>*right ? (*left + 1): (*right + 1);
            return true;
        }
    }

    return false;
}