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
class BSTIterator {
    Queue<TreeNode> q = new LinkedList<>();

    public BSTIterator(TreeNode root) {
        inOrderTraversal(root);
    }
    
    private void inOrderTraversal(TreeNode t) {
        if (t.left != null) {
            inOrderTraversal(t.left);          
        }
        this.q.add(t);
        if (t.right != null) {
            inOrderTraversal(t.right);         
        }
    }
    
    public int next() {
        TreeNode next = q.poll();
        return next.val;
    }
    
    public boolean hasNext() {
        return !q.isEmpty();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */