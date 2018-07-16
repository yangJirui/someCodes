/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> query_stack;
        vector<int> path;

        TreeNode* current_node = root;
        TreeNode* recent = nullptr; //用于存储最近访问的节点

        while (current_node != nullptr || !query_stack.empty())
        {
            while (current_node)
            {
                query_stack.push(current_node);
                current_node = current_node->left;
            }

            TreeNode* top = query_stack.top();

            if (top->right && top->right != recent)//若右节点还没有访问则需要先将右节点入栈
            {
                current_node = top->right;
            }
            else //没有（子）右节点时，或右节点被访问过
            {
                path.push_back(top->val);
                recent = top;
                query_stack.pop();
            }
        }
        return path;
    }
};