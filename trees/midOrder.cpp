# include<iostream>
# include<vector>
# include<stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void midOrder(TreeNode* root, vector<int>& path)
{
	stack<TreeNode*> node_stack;
	if (root == nullptr) return;
	while (!node_stack.empty() || root != nullptr)
	{
		while (root != nullptr)
		{
			node_stack.push(root);
			root = root->left;
		}

		TreeNode* top = node_stack.top();
		path.push_back(top->val);
		node_stack.pop();

		if (top->right != nullptr) root = top->right;
	}
	return;
}

void midOrder_re(TreeNode* root, vector<int>& path)
{
	if (root == nullptr) return;

	midOrder_re(root->left, path);
	path.push_back(root->val);
	midOrder_re(root->right, path);

}

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	vector<int> path;
	midOrder_re(root, path);
	for (auto a : path)
		cout << a << " ";
	cout << endl;

	cout << "******" << endl;
	vector<int> path1;
	midOrder(root, path1);
	for (auto a : path1)
		cout << a << " ";
	cout << endl;

	path.clear();
	midOrder_re(root, path);

	for (auto a : path)
		cout << a << " ";
	cout << endl;


}
