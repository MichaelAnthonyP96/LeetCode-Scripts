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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        // base case where the start and end index overlap
        if (end <= start)
        {
            return nullptr;
        }
        
        // get the middle index, which rounds down in integer arithmetic
        int middle = (start + end) / 2;
        // create the root node
        auto* root = new TreeNode(nums[middle]);
        // recursively create the left subtree
        root->left = sortedArrayToBST(nums, start, middle);
        // recursively create the right subtree, starting with middle + 1 because integer division rounds down
        root->right = sortedArrayToBST(nums, middle+1, end);
        return root;
    }
};
