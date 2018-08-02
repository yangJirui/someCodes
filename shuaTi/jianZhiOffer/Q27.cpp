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

void exchange(Node* root)
{
    if(root ==nullptr)
        return;
    // cout<<root->x<<endl;
    
    exchange(root->left);
    cout<<"exchage"<<endl;
    Node* tmp = root->right;
    root->right = root->left;
    root->left = tmp;
    exchange(root->left);  
}

Node* make_tree()
{
    // return new Node(8, new Node(6, new Node(5), new Node(7)), 
    //                    new Node(10, new Node(9), new Node(11)));

    return new Node(8, new Node(7, new Node(6), nullptr), nullptr);

}

void print_tree(Node* root)
{
    if (root==nullptr)
        return ;
    cout<<root->x<<endl;
    print_tree(root->left);
    print_tree(root->right);
}

int main()
{
    Node* root = make_tree();
    print_tree(root);
    cout<<"_____"<<endl;
    exchange(root);

    print_tree(root);
}