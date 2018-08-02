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

void post(Node* root)
{
    if (root ==nullptr)
        return ;

    post(root->left);
    post(root->right);

    cout<<root->x<< " ";
}

void post_order(Node* root)
{
    /*
    先访问左子树， 再访问右子树， 最后访问根节点。
    当用栈来存储节点， 必须分清返回根节点时，是左子树返回还是右子树返回。
    所以用辅助指针recent指向其最近访问过的节点。

    */
    Node* current_node = root;
    Node* recent = nullptr;

    stack<Node* > path_stack;

    while(current_node!=nullptr|| !path_stack.empty())
    {
        while(current_node)
        {
           path_stack.push(current_node);
           current_node = current_node->left;
        }

        if(!path_stack.empty())
        {
            Node* top = path_stack.top();
            if (top->right && top->right != recent)
            {
                current_node = top->right;
            }

            else
            {
                cout<<top->x<<" ";
                recent = top;
                path_stack.pop();
            }
        }
    }
}

Node* creat_tree()
{
    return new Node(1, new Node(2, new Node(4), nullptr),
                       new Node(3, new Node(5), new Node(6)));
}


int main()
{
    Node* root = creat_tree();

    post(root);
    cout<<endl<<"*****"<<endl;

    post_order(root);
    cout<<endl;
}