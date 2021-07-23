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
    vector<int> inorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> pendingNodes;
        std::vector<int> returnVals;
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
                returnVals.push_back(itr->val);
                // move to the right subtree of this node
                itr = itr->right;
            }
        } while(itr != nullptr || !pendingNodes.empty());
        // continue processing while the stack is not empty and our iterator is still valid
        return returnVals;
    }
};
