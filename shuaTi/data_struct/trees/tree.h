#include<iostream>

struct BinaryTreeNode
{
  int data;

  BinaryTreeNode * left;
  BinaryTreeNode * right;

  BinaryTreeNode() = default;
  BinaryTreeNode(int data): data(data), left(nullptr), right(nullptr) {}

  BinaryTreeNode(int data, BinaryTreeNode *leftp, BinaryTreeNode *rightp): data(data), left(leftp), right(rightp) {}

};
