struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> midOrder(TreeNode* root)
{   /*
    中序遍历：左中右。因此先不断将左节点压栈；然后连续出栈2次（并打印），入栈右节点
    */
    vector<TreeNode* > stack;
    vector<int> path;
    
    TreeNode* current_node = root;
    while (!stack.empty() || current_node!=nullptr)
    {
        while (current_node)
        {
            stack.push_back(current_node); // 不断压栈左节点
            current_node = current_node->left;
        }
        TreeNode* top=nullptr ;
        
        for (int i = 0; i < 2 && stack.size()!=0; i++)
        {   
            top = *(stack.end() - 1);
            stack.erase(stack.end() - 1); //出栈两次，这里注意小心栈变空，所以限制加一个条件
            //cout << top->val << " +";
            path.push_back(top->val);
        }
        current_node = top->right; //将右节点赋值给current_node，待会就会将右子节点入站。
    }
    return path;
    
}