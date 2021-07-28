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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL)
        {
            return NULL;
        }
        int count = 0;
        if (t1 != NULL)
        {
            count += t1->val;
        }
        if (t2 != NULL)
        {
            count += t2->val;
        }
        
        
        auto t3 = new TreeNode(count);
        t3->left = mergeTrees(t1 ? t1->left : NULL, t2 ? t2->left : NULL);
        t3->right = mergeTrees(t1 ? t1->right : NULL, t2 ? t2->right : NULL);
        return t3;
    }
};