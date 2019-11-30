// 145 Binary Tree Postorder Traversal.java

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
// a trivial solution using recursion
// time: O(n), space: O(n); n is number of nodes in tree
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        if (root == null) return new ArrayList<Integer> ();

        List<Integer> left = postorderTraversal(root.left);
        List<Integer> right = postorderTraversal(root.right);

        List<Integer> ans = new ArrayList<Integer> ();
        
        if (left != null)	ans.addAll (left);
        if (right != null)	ans.addAll (right);

        ans.add(root.val);

        return ans;
    }
}

// a more complex way using iterations (instead of recursion)
// using stack
// time: O(n), space O(n)
// logic a bit too complex?
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        if (root == null) return new ArrayList<Integer> ();

        List<Integer> ans = new ArrayList<Integer> ();
        Stack<TreeNode> stack = new Stack<TreeNode> ();
        stack.push (root);
        TreeNode temp = root, parent, child = root;

        while (!stack.empty()) {
        	parent = temp;
        	if (temp.right != null)	{
        		stack.push(temp.right);
        	}
        	if (temp.left != null) {
        		stack.push(temp.left);
        	}

        	if (temp.right == child) {
        		stack.pop();
        		if (temp.left != null) stack.pop();
        	}
        	if (temp.left == child) {
        		stack.pop();
        	}

        	temp = stack.peek();

        	if (parent == temp) {
        		child = stack.pop();
        		ans.add (child.val);
        		if (!stack.empty()) temp = stack.peek();
        	}

        }

        return ans;
    }
}