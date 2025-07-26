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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return false;
        }

        return recurseSubtree(root, 0, targetSum);
    }

    boolean recurseSubtree(TreeNode root, int currSum, int targetSum) {
        currSum += root.val;
        if (root == null) return false;
        if (root.left == null && root.right == null) {
            return (currSum == targetSum);
        } else {
                if (root.left != null && recurseSubtree(root.left, currSum, targetSum)) {
                    return true;
                }
                if (root.right != null && recurseSubtree(root.right, currSum, targetSum)) {
                    return true;
                }
            }
        return false;
    }
}