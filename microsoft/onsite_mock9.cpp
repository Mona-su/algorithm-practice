// Given an array where elements are sorted in ascending order, 
// convert it to a height balanced BST.
// For this problem, a height-balanced binary tree is defined as 
// a binary tree in which the depth of the two subtrees of every 
// node never differ by more than 1.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursion
// time: O(n), space: O(1)?
class Solution {
private:
    TreeNode* bst(vector<int>& nums, int start, int end) {
        TreeNode* ans;
        if (end - start == 1) {
            ans = new TreeNode(nums[start]);
            return ans;
        }
        else if (end == start) {
            return NULL;
        }
        
        int half = (start + end) / 2;
        ans = new TreeNode(nums[half]);
        ans->left = bst(nums, start, half);
        ans->right = bst(nums, half+1, end);
        
        return ans;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bst(nums, 0, nums.size());
    }
};