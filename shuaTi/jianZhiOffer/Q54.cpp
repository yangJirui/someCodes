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



int find_kth(Node* root, int &count, int k)
{
  
  if(root ==nullptr|| k<=0)
    return -1;
  int target = -1;
  if(root->left)
    target =find_kth(root->left, count, k);

    count ++;

    if(count==k)
    return root->x;

  if(target==-1&& root->right!=nullptr)
    target = find_kth(root->right, count, k);
  
  return target;
}

int main()
{
    Node* root = new Node(5, new Node(3, new Node(2), new Node(4)), 
                             new Node(7, new Node(6), new Node(8)));
    
    
    for(int i=0; i<7;i++)
    {
        int count = 0;
         cout<<find_kth(root, count, i+1)<<endl;
    }
   
}