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
    TreeNode* increasingBST(TreeNode* root) {
        std::stack<TreeNode*> pendingNodes;
        TreeNode* newRoot = nullptr;
        TreeNode* rightChildItr = nullptr;
        // start at the root node
        auto itr = root;
        do
        {
            // Add each left subchild to the stack until we reach a nullptr
            while (itr != nullptr)
            {
                pendingNodes.push(itr);
                itr = itr->left;
            }
            // if we are a nullptr and the stack still contains values...
            if (itr == nullptr && !pendingNodes.empty())
            {
                // pop the last valid node
                itr = pendingNodes.top();
                pendingNodes.pop();
                // add the value to the results
                if (newRoot == nullptr)
                {
                    newRoot = new TreeNode(itr->val);
                    rightChildItr = newRoot;
                }
                else
                {
                    rightChildItr->right = new TreeNode(itr->val);
                    rightChildItr = rightChildItr->right; 
                }
                
                // move to the right subtree of this node
                itr = itr->right;
            }
        } while(itr != nullptr || !pendingNodes.empty());
        // continue processing while the stack is not empty and our iterator is still valid
        return newRoot;
    }
};