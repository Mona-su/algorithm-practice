// 236. Lowest Common Ancestor of a Binary Tree

// Given a binary tree, find the lowest common ancestor (LCA) of two 
// given nodes in the tree.
// According to the definition of LCA on Wikipedia: “The lowest common 
// ancestor is defined between two nodes p and q as the lowest node in 
// T that has both p and q as descendants (where we allow a node to be 
// a descendant of itself).”

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// dfs, one pass
// time O(n) (n: number of nodes)
class Solution {
private:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((root == p) || (root == q)) {
            return root;
        }

        TreeNode* left = (root->left == NULL) ? NULL : dfs(root->left, p, q);
        TreeNode* right = (root->right == NULL) ? NULL : dfs(root->right, p, q);

        return (left == NULL) ? right : ((right == NULL) ? left : root);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)   return NULL;
        if (q == NULL)  return p;
        if (p == NULL)  return q;
        if (root == q || root == q) return root;
        return dfs(root, p, q);
    }
};