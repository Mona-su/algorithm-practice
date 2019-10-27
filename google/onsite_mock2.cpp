// 1161. Maximum Level Sum of a Binary Tree

// Given the root of a binary tree, the level of its root is 1, the level of 
// its children is 2, and so on.
// Return the smallest level X such that the sum of all the values of nodes 
// at level X is maximal.

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
    int maxLevelSum(TreeNode* root) {
        if (root == NULL)   return 0;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int curr_level = 1, max_level = 0, Max = 0, curr = 0;
        while (!nodes.empty()) {
            int len = nodes.size();
            for (int i = 0; i < len; i++) {
                TreeNode* temp = nodes.front();
                nodes.pop();
                curr += temp->val;
                if (temp->left != NULL)
                    nodes.push(temp->left);
                if (temp->right != NULL)
                    nodes.push(temp->right);
            }
            if (curr > Max) {
                Max = curr;
                max_level = curr_level;
            }
            curr_level++;
            curr = 0;
        }
        return max_level;
    }
};