/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getHeight(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftHeight = 0, rightHeight = 0;
        if (root->left)
        {
            leftHeight = getHeight(root->left);
        }
        if (root->right)
        {
            rightHeight = getHeight(root->right);
        }
        return std::max(leftHeight, rightHeight) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        if (!isBalanced(root->left) || !isBalanced(root->right))
        {
            return false;
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        return std::abs(leftHeight - rightHeight) <= 1;   
    }
};