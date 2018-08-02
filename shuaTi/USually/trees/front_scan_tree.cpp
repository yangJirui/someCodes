#include<iostream>
# include<stack>

using namespace std;

struct Node
{
  int x;
  Node* left;
  Node* right;

  Node() = default;
  Node(int xx): x(xx), left(nullptr), right(nullptr){}
  Node(int xx, Node* l, Node* r): x(xx), left(l), right(r){}
};

void print_recurrent(Node* root)
{
    if(root == nullptr)
        return ;
    
    cout<<root->x<<" ";
    print_recurrent(root->left);
    print_recurrent(root->right);

}

void create_tree(root)
{

}
void front_print_tree(Node* root)
{
    if (root==nullptr)
        return;

    stack<Node*> path_stack;
    Node* current_node = root;

    while(current_node!=nullptr || !path_stack.empty())
    {
        while(current_node)
        {
            cout<<current_node->x<<" "; //访问

            path_stack.push(current_node);
            current_node = current_node->left;

        }
        
        if(path_stack.size())
        {
            Node* top = path_stack.top();
            path_stack.pop();

            current_node = top->right; // 变换方向
        }
    }
}
