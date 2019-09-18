// 1145. Binary Tree Coloring Game.cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	// implement using stack
	// TreeNode* findNode(TreeNode* root, int x) {
	// 	stack<TreeNode*> nodes;
	// 	nodes.push(root);
	// 	while (!nodes.empty()) {
	// 		TreeNode* temp = nodes.top();
	// 		nodes.pop();
	// 		if (temp->val == x)
	// 			return temp;
	// 		if (temp->left != NULL)
	// 			nodes.push(temp->left);
	// 		if (temp->right != NULL) {
	// 			nodes.push(temp->right);
	// 		} 
	// 	}
	// 	return NULL;
	// }

	// implement using queue
	TreeNode* findNode(TreeNode* root, int x) {
		queue<TreeNode*> nodes;
		nodes.push(root);
		while (!nodes.empty()) {
			TreeNode* temp = nodes.front();
			nodes.pop();
			if (temp->val == x)
				return temp;
			if (temp->left != NULL)
				nodes.push(temp->left);
			if (temp->right != NULL) {
				nodes.push(temp->right);
			} 
		}
		return NULL;
	}

	int countSubtree(TreeNode *node) {
		if (node == NULL) {
			return 0;
		}
		return (countSubtree(node->left) + countSubtree(node->right) + 1);
	}

public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        // find the TreeNode with value x
        TreeNode *xNode = findNode (root, x);

        // check the number of nodes in subarray if choosing TreeNode x's parent or children
        int left = countSubtree(xNode->left);
        int right = countSubtree(xNode->right);
        int parent = n - left - right - 1;
        int maxNodes = max(max(left, right), parent);
        
        // compare with n/2
        return maxNodes > (n/2);
    }
};