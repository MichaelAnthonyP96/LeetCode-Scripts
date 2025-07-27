/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        return recurseSubTree(root, new ArrayList<>());
        
    }

    ArrayList<Integer> recurseSubTree(TreeNode root, ArrayList<Integer> result) {
        // Add ourself first
        if (root != null) {
            result.add(root.val);
        } else {
            return result;
        }

        // then add the left subtree
        if (root.left != null) {
            recurseSubTree(root.left, result);
        }

        // then add the right subtree
        if (root.right != null) {
            recurseSubTree(root.right, result);
        }

        return result;
    }
}