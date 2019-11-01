// 1110. Delete Nodes And Return Forest

// Given the root of a binary tree, each node in the tree has a distinct value.
// After deleting all nodes with a value in to_delete, we are left with a forest 
// (a disjoint union of trees).
// Return the roots of the trees in the remaining forest.  You may return the 
// result in any order.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// post-order traversal
class Solution {
private:
    vector<TreeNode*> ans;
    void postTrav(TreeNode* node, unordered_set<int>& to_delete) {
        if (node == NULL)
            return;
        postTrav(node->left, to_delete);
        postTrav(node->right, to_delete);
        
        if (node->left != NULL) {
            if (to_delete.count(node->left->val) > 0)
                node->left = NULL;
        }
        if (node->right != NULL) {
            if (to_delete.count(node->right->val) > 0)
                node->right = NULL;
        }
        if (to_delete.count(node->val) > 0) {
            if (node->left != NULL)
                ans.push_back(node->left);
            if (node->right != NULL)
                ans.push_back(node->right);
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (root == NULL)   return ans;
        unordered_set<int> deleted(to_delete.begin(), to_delete.end());
        if (deleted.count(root->val) == 0)
            ans.push_back(root);
        postTrav(root, deleted);
        return ans;
    }
};

// BFS
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> deleted(to_delete.begin(), to_delete.end());
        queue<TreeNode*> nodes;
        nodes.push(root);
        if (deleted.count(root->val) == 0)
            ans.push_back(root);
        TreeNode *curr;
        bool delete_left, delete_right;
        while (!nodes.empty()) {
            delete_left = delete_right = false;
            curr = nodes.front();
            nodes.pop();
            if (curr->left != NULL) {
                nodes.push(curr->left);
                if (deleted.count(curr->left->val) > 0) {
                    curr->left = NULL;
                    delete_left = true;
                }
            }
            if (curr->right != NULL) {
                nodes.push(curr->right);
                if (deleted.count(curr->right->val) > 0) {
                    curr->right = NULL;
                    delete_right = true;
                }
            }
            if (deleted.count(curr->val) > 0) {
                if (curr->left != NULL) 
                    if (!delete_left)
                        ans.push_back(curr->left);
                if (curr->right != NULL) 
                    if (!delete_right) 
                        ans.push_back(curr->right);
            }
        }
        return ans;
    }
};