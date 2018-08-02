#include<iostream>
#include<vector>
#include<stack>

using namespace std;
struct Node
{
    int x;
    Node* left;
    Node* right;

    Node() = default;

    Node(int a): x(a), left(nullptr), right(nullptr) {}
    Node(int a, Node* l, Node* r): x(a), left(l), right(r) {}
};



Node* find_two_node_father(Node* root, int x1, int x2)
{
    

    if(root == nullptr)
        return nullptr;
    
    if(root->x==x1||root->x==x2)
        return root;

    Node* left_find = find_two_node_father(root->left, x1, x2);
    Node* right_find = find_two_node_father(root->right, x1, x2);

    if(left_find&&right_find)
        return root;
    if(left_find==nullptr)
        return right_find;
    if(right_find==nullptr)
        return left_find;
}


Node* create()
{
    return new Node(1, new Node(2, new Node(4, new Node(8), nullptr), new Node(5, nullptr, new Node(9))), 
                       new Node(3, new Node(6), new Node(7)));
}


void print_tree(Node* root)
{
   stack<Node*> path;

   Node* current = root;
   while(root!=nullptr|| !path.empty())
   {

     while(root)
     {
        path.push(root);
        cout<<root->x<<" ";

        root = root->left;
     }

     root = path.top();
     path.pop();
     root = root->right;
   }
}

void front_pr(Node* root)
{
    if (root == nullptr)
        return ;

    cout<<root->x<<" ";
    front_pr(root->left);
    front_pr(root->right);
}
int main()
{
    Node* root = create();
    

    print_tree(root);
    cout<<endl<<"***"<<endl;
    front_pr(root);
    cout<<endl;
    bool find_node1 = false;
    bool find_node2 = false;
    Node* finded = find_two_node_father(root, 8, 9);

    cout<<finded->x<<endl;
    cout<<"___"<<endl;

}