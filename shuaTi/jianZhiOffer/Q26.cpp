#include<iostream>

using namespace std;

struct Node
{
    int x;
    Node* left, right;
    Node() = default;

    Node(int data):x(data), left(nullptr), right(nullptr){}

    Node(int data, Node*l, Node* r): x(data), left(l), right(r){}

};

bool find_sub_tree(Node* root1, Node* root2)
{
    if(root2 == nullptr)
        return true;
    if(root1 == nullptr)
        return false;

    if(root1->x != root2->x)
        return false;

    return find_sub_tree(root1->left, root2->left)&&(root1->right, root2->right);
}
bool have_sub_tree(Node* root1, Node* root2)
{
    
    bool result = false;

    if(root1!=nullptr && root2 != nullptr)
    {
        if (root1->x == root2->x)
            result = find_sub_tree(root1, root2);
        if(!result)
        {
            result = have_sub_tree(root1->left, root2)
        }
        if(!result)
            result = have_sub_tree(root1->right, root2)
    }

    return result;
}