#include<iostream>
#include<queue>
#include<stack>
#include<cstring>

using namespace std;

struct Node
{
    char x;
    Node* left ;
    Node *right;
    Node() = default;

    Node(char data):x(data), left(nullptr), right(nullptr){}

    Node(char data, Node*l, Node* r): x(data), left(l), right(r){}

};


Node* reverse_tree(char* str, int &index)
{
   if(str==nullptr)
    return nullptr;
   Node* root = nullptr;
   if(str[index]!='$')
   {  
      root = new Node(str[index]);
      index++;
      root->left = reverse_tree(str, index);
      root->right = reverse_tree(str, index);
   }
   else index++;
   return root;
}

void print_tree_line(Node*root)
{
    if(root == nullptr)
        return ;
    queue<Node*> node_queue;
    node_queue.push(root);
    int no_print_num = 1;
    int next_level_num = 0;

    while(node_queue.size())
    {
        Node* top = node_queue.front();
         
        if(top->left)
        {
            next_level_num++;
            node_queue.push(top->left);
        }
        if(top->right)
        {
            next_level_num++;
            node_queue.push(top->right);
        }
        cout<< top->x<<" ";
        node_queue.pop();
        no_print_num -- ;
        if(no_print_num==0)
        {
          cout<<endl;
          no_print_num = next_level_num;
          next_level_num = 0;
        }

    }
}
int main()
{   
    char* str = "124$$$35$$6$$";
    int index = 0;
    Node* root = reverse_tree(str, index);
    print_tree_line(root);
}