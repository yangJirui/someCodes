#include<iostream>
#include<queue>

using namespace std;
struct Node
{
    int x;
    Node* left;
    Node* right;

    Node() = default;
    Node(int data): x(data), left(nullptr), right(nullptr){}
    Node(int x, Node*l, Node* r): x(x), left(l), right(r){}

};


Node* create_binarySortTree_by_sortedList(int *array, int index, int N)
{
 
   if(array==nullptr)
      return nullptr;

   if(index>=N)
      return nullptr;

   Node* root = new Node(array[index]);
   
   if((index+1)<N && array[index+1]<root->x)
   {
      root->left = create_binarySortTree_by_sortedList(array, index+1, N);
   }
  
  if((index+1)< N && array[index+1]>=root->x) 
     root->right = create_binarySortTree_by_sortedList(array, index+1, N);

  return root;
}

void print_tree_byLine(Node* root)
{

    if(root==nullptr)
        return;

    queue<Node* > node_queue;
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

        cout<<top->x<<" ";
        node_queue.pop();
        no_print_num -- ;
        if(no_print_num==0)
        {
            no_print_num= next_level_num;
            next_level_num = 0;
            cout<<endl;
        }
    }
}

void add_node_to_BST(Node** root, Node* new_node)
{

    if(new_node==nullptr)
        return ;
    if(*root == nullptr)
        {
            *root = new_node;
            return ;
        }
    // if(root->right==nullptr&& root->left==nullptr)
        
    //     {
    //         if(new_node->x >= root->x)
    //             root->right = new_node;
    //         else
    //             root->left = new_node;
    //         return ;
    //     }

    if(new_node->x < (*root)->x)
        add_node_to_BST(&((*root)->left), new_node);
    else
        add_node_to_BST(&((*root)->right), new_node);
}

Node* create_node_by_cin()
{
    Node* root = nullptr;
    int data;

    if(cin>>data)
    {
        root = new Node(data);
    }
    else return nullptr;

    while(cin>>data)
    {
        add_node_to_BST(&root, new Node(data));
    }
    return root;
}
int main()
{
   Node* root= create_node_by_cin();
   print_tree_byLine(root);
}