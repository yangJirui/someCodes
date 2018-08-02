#include<iostream>
#include<stack>
#include<queue>

using namespace std;

struct TreeNode
{
    int x;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int a): x(a), left(nullptr), right(nullptr){}
    TreeNode(int a, TreeNode* l,TreeNode*r): x(a), left(l), right(r){}
};


void convert_tree_to_list(TreeNode* root, TreeNode** tail)

{
    if(root==nullptr||  tail == nullptr)
        return ;

    convert_tree_to_list(root->left, tail);

    root->left = *tail;
    
    TreeNode* real_right = root->right;
    if((*tail)!=nullptr)
        (*tail)->right = root;

    (*tail) = root;

    convert_tree_to_list(real_right, tail);
}

TreeNode* convert(TreeNode* root)
{
    TreeNode * tail=nullptr;
    
    convert_tree_to_list(root, &tail);
    
    TreeNode* head = tail;
    while(head!=nullptr && head->left != nullptr)
       head = head->left;
    return head;
} 
TreeNode* create_binary_search_tree(int *array, int st, int end)
{
    if(end-st<0)
        return nullptr;
    int mid_index= (end+st)>>1;
    
    TreeNode* root = new TreeNode(array[mid_index]);

    root->left = create_binary_search_tree(array, st, mid_index-1);
    root->right = create_binary_search_tree(array, mid_index+1, end);
    return root;
}
void print_tree_each_line(TreeNode* root)
{
    if(root==nullptr)
        return ;
    queue<TreeNode*> path;
    int no_print_num =1;
    int next_level_num = 0;
    path.push(root);
    while(!path.empty())
    {
       TreeNode* top = path.front();
       if(top->left) 
        {
            path.push(top->left);
            next_level_num++;
        }
       if(top->right) 
        {
            path.push(top->right);
            next_level_num ++;
        }

       cout<<top->x<<" ";
       path.pop();
       no_print_num -- ;
       if(no_print_num==0)
       {
        cout<<endl;
        no_print_num = next_level_num;
        next_level_num = 0;
       }

    }
    cout<<"******"<<endl;
}

void print_dual_list(TreeNode*head)
{   
    if(head == nullptr)
        return ;
    TreeNode* tail = head;

    while(tail!=nullptr&&tail->right!=nullptr)
    {
        cout<<tail->x<<" ";
        tail = tail->right;
    }
    cout<<tail->x<<endl;

    TreeNode* p = tail;
    while(p!=nullptr)
    {
        cout<<p->x<<" ";
        p = p->left;
    }
    cout<<endl;
    cout<<"________"<<endl;
}
int main()
{   
    int list[] = {4, 6, 8, 10, 12, 14, 16};
    int N=7;
    // int list[] = {5, 6, 10, 11, 12};
    // int N=5;
    TreeNode* root = create_binary_search_tree(list, 0, N-1);
    print_tree_each_line(root);
    TreeNode* head = convert(root);
    print_dual_list(head);
}