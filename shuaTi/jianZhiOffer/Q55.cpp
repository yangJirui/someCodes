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


int find_depth(Node* root)
{

    if(root==nullptr)
        return 0;
    int left = 0;
    int right = 0;
    if(root->left) left = find_depth(root->left);
    if(root->right) right = find_depth(root->right);
    

    return left>right? (left+1): (right+1);
}

int main(int argc, char const *argv[])
{
    /* code */
    Node* root = new Node(1, new Node(2, new Node(4), new Node(5, new Node(7), nullptr)),
                             new Node(3, nullptr, new Node(6)));

    cout<<find_depth(root)<<endl;
}