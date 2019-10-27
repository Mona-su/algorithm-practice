// 1123. Lowest Common Ancestor of Deepest Leaves.cpp
// Given a rooted binary tree, return the lowest common ancestor of its deepest leaves.

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
public:
	int findDeepest (TreeNode *root) {
		if (root == NULL)	return 0;
		return 1 + max(findDeepest(root->left), findDeepest(root->right));
	}

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == NULL)	return NULL;
        int l = findDeepest(root->left);
        int r = findDeepest(root->right);
        if (l == r) {
        	return root;
        }
        else if (l < r) {
        	return lcaDeepestLeaves(root->right);
        }
        else {
        	return lcaDeepestLeaves(root->left);
        }
    }
};



class Solution {
private:
	TreeNode *temp = new TreeNode(0), *left = new TreeNode(0), *right = new TreeNode(0);
	int deepest = -1, depth;
public:
	
	TreeNode* findDeepest (TreeNode *root) {
		// int left = 0, right = 0;

		if (root == NULL) {
			// lca = root;
			temp->left = NULL;
			temp->val = 0;
			return temp;
		}

		left = findDeepest(root->left);
		left->val = left->val + 1;
		right = findDeepest(root->right);
		right->val = right->val + 1;

		if (left->val < right->val) {
			return right;
		}
		else if (right->val < left->val) {
			return left;
		}
		else {
			temp->left = root;
			temp->val = left->val;
			return temp;
		}
	}

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // init();
        return findDeepest(root)->left;
    }
};