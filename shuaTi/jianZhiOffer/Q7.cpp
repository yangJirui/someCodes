#include<iostream>

using namespace std;

struct Node
{
    int x;
    Node * left;
    Node * right;

    Node() = default;
    Node(int data): x(data), left(nullptr), right(nullptr) {};
    Node(int data, Node* l, Node* r): x(data), left(l), right(r) {};
};

void pre_print(Node* root)
{
    if (root == nullptr)
    {
        // cout<<"tree is null"<<endl;
        return;
    }

    cout<<root->x<<endl;
    pre_print(root->left);
    pre_print(root->right);
}

void mid_print(Node* root)
{
    if (root == nullptr)
    {
        // cout<<"tree is null"<<endl;
        return;
    }
    mid_print(root->left);
    cout<<root->x<<endl;
    mid_print(root->right);

}

Node * remake(const int * pre_array, int pre_st, int pre_end,
              const int * mid_array, int mid_st, int mid_end)
{

    int root_value = pre_array[pre_st];
    cout<<root_value<<endl;
    Node * root_node = new Node(root_value);

    if(mid_st == mid_end && pre_st == pre_end&& pre_array[pre_st]==mid_array[mid_st])
    {
        return root_node;
    }
    // find root index in the mid_arry
    int root_index_in_midarray;
    for(int i=mid_st; i<=mid_end; i++)
    {
        if (mid_array[i] == root_value)

        {
            root_index_in_midarray = i;
            break;
        }

    }
    int left_length = root_index_in_midarray - mid_st;
    if(left_length>0)
    {
        root_node->left = remake(pre_array, pre_st+1, pre_st+ left_length,
                                 mid_array, mid_st, root_index_in_midarray-1);
    }
    if(left_length< pre_end - pre_st)
    {
        root_node->right = remake(pre_array, pre_st+left_length+1,  pre_end,
                                  mid_array, root_index_in_midarray+1, mid_end);
        // return root_node;
    }
    return root_node;
}

int main()
{
//    int pre_array[] = {1, 2, 4, 3};
//    int mid_array[] = {2, 4 ,1, 3};

     int pre_array[] = {1, 2, 4, 7, 3, 5, 6, 8};
     int mid_array[] = {4, 7, 2, 1, 5, 3, 8, 6};

    // int pre_index=0;
    // cout<<pre_index<<endl;
    Node * root = remake(pre_array, 0, 7,
                         mid_array, 0, 7);
    cout<<"remake over"<<endl;

    pre_print(root);
    cout<<"*****"<<endl;
    mid_print(root);
}