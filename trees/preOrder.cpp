/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using namespace std;
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        
        vector<TreeNode* > stack;
        vector<int> path;
        if (root == nullptr) return path;
        stack.push_back(root);

        while (!stack.empty())
        {
            TreeNode* top = *(stack.end() - 1);
            stack.erase(stack.end() - 1);
   
            path.push_back(top->val);

            if (top->right) stack.push_back(top->right);
            if (top->left) stack.push_back(top->left);
        }
        return path;
    }
};