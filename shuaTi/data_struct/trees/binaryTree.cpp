#include<iostream>
#include"tree.h"

using namespace std;

BinaryTreeNode* create_tree()
{
    int data;
    cin>>data;
    if (data == -1)
    {
        return nullptr;
    }
    else
    {
        BinaryTreeNode *new_node = new BinaryTreeNode(data);
        new_node->left = create_tree();
        new_node->right = create_tree();
        return new_node;
    }
}
BinaryTreeNode* create_default_tree()
{
    BinaryTreeNode *tree_root = new BinaryTreeNode(1);
    tree_root->left = new BinaryTreeNode(2, new BinaryTreeNode(4), new BinaryTreeNode(5));
    tree_root->right = new BinaryTreeNode(3, nullptr, new BinaryTreeNode(6));

    return tree_root;
}
void preorder_print_tree(BinaryTreeNode *tree_root)
{
    if (tree_root==nullptr)
        return;

    cout<<tree_root->data<<endl;
    preorder_print_tree(tree_root->left);
    preorder_print_tree(tree_root->right);
}

void inorder_print_tree(BinaryTreeNode *tree_root)
{
    if (tree_root == nullptr)
        return;

    inorder_print_tree(tree_root->left);
    cout<<tree_root->data<<endl;
    inorder_print_tree(tree_root->right);
}

void poorder_print_tree(BinaryTreeNode *tree_root)
{
    if (tree_root == nullptr)
        return;
    poorder_print_tree(tree_root->left);
    poorder_print_tree(tree_root->right);
    cout<<tree_root->data<<endl;
}

int main()
{
    // BinaryTreeNode * tree_root = create_tree();
    BinaryTreeNode * tree_root = create_default_tree();
    cout<<"create tree over"<<endl;

    preorder_print_tree(tree_root);
    cout<<"___________"<<endl;

    inorder_print_tree(tree_root);
    cout<<"___________"<<endl;

    poorder_print_tree(tree_root);
    cout<<"___________"<<endl;
}