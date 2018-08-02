#include<iostream>
#include<queue>
#include<stack>

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

void print_tree_core(Node* root)
{
    if(root==nullptr)
        return; 
    // cout<<root->x;
    if(root->left!=nullptr)
        cout<<root->left->x<<" ";
    if(root->right!=nullptr)
        cout<<root->right->x<<" ";
    print_tree_core(root->left);
    print_tree_core(root->right);
}

void print_tree(Node* root)
{
    if(root ==nullptr)
        return ;
    cout<<root->x<<" "<<endl;
    print_tree_core(root);

    cout<<endl;
}

Node* create_tree(int num)
{
    if(num==0)
    {
        return new Node(8, new Node(6, new Node(5), new Node(7)),
                           new Node(10, new Node(9), new Node(11)));
    }

    if(num==1)
    {
        return new Node(1, new Node(2, new Node(3), nullptr), nullptr);
    }

    if(num==2)
    {
        return new Node(1, nullptr, new Node(2, nullptr, new Node(3)));
    }
}
/**************************************************/

void print_tree_by_queue(Node* root)
{
   if(root==nullptr)
     return;
   queue<Node*> node_queue;
   node_queue.push(root);

   while(!node_queue.empty())
   {
    Node* tmp = node_queue.front();
    cout<<tmp->x<<" ";
    node_queue.pop();
    if(tmp->left!=nullptr)  node_queue.push(tmp->left);
    if(tmp->right!=nullptr) node_queue.push(tmp->right);
   }

}
void print_tree_by_queue_huanHang(Node* root)
{
    if(root == nullptr)
        return;
    queue<Node*> node_queue;

    node_queue.push(root);
    int no_print_num = 1;
    int next_level_num = 0;
    while(!node_queue.empty())
    {
         Node* tmp = node_queue.front();
         if(tmp->left) next_level_num++;
         if(tmp->right) next_level_num++;
         node_queue.pop();
         cout<<tmp->x<<" ";
         no_print_num --;
         if(no_print_num==0)
            {
                cout<<endl;
                no_print_num = next_level_num;
                next_level_num = 0;
            }
         if(tmp->left)
            node_queue.push(tmp->left);
         if(tmp->right)
            node_queue.push(tmp->right);
    }
}
void print_tree_z(Node* root)
{
  
}
int main()
{
    for(int i=0; i<3;i ++)
    {
        Node* root = create_tree(i);
        // print_tree(root);
        // print_tree_by_queue(root);
        // print_tree_by_queue_huanHang(root);
        print_tree_z(root);
        cout<<"______"<<endl;
    }
}