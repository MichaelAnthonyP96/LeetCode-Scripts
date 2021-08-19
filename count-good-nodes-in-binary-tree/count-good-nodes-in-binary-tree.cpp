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
    int goodNodes(TreeNode* root, int max)
    {
        if (nullptr == root)
        {
            return 0;
        }
        int count = 0;
        if (root->val >= max)
        {
            ++count;
            max = root->val;
        }
        if (root->right)
        {
            count += goodNodes(root->right, max);
        }
        if (root->left)
        {
            count += goodNodes(root->left, max);
        }
        return count;
    }
    
    int goodNodes(TreeNode* root) {
        if (nullptr == root)
        {
            return 0;
        }
        return goodNodes(root, INT_MIN);
    }
};