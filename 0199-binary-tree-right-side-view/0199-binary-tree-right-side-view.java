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
    public List<Integer> rightSideView(TreeNode root) {
        if (root == null) return new ArrayList<>();
        ArrayList<Integer> result = new ArrayList<>();
        Deque<TreeNode> nextLevel = new ArrayDeque<>();
        Deque<TreeNode> currLevel = new ArrayDeque<>();
        nextLevel.offer(root);

        while(!nextLevel.isEmpty()){
            currLevel = nextLevel;
            nextLevel = new ArrayDeque<>();
            result.add(currLevel.getLast().val);

            while (!currLevel.isEmpty()) {
                TreeNode curr = currLevel.poll();
                if (curr.left != null) {
                    nextLevel.offer(curr.left);
                }
                if (curr.right != null) {
                    nextLevel.offer(curr.right);
                }
            }
        }

        return result;
    }
}