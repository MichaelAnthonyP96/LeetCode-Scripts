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
        auto itr = root;
        do
        {
            while (itr != nullptr)
            {
                std::cout << "Checkpoint 1" << std::endl;
                pendingNodes.push(itr);
                itr = itr->left;
            }
            if (itr == nullptr && !pendingNodes.empty())
            {
                std::cout << "Checkpoint 2" << std::endl;
                itr = pendingNodes.top();
                pendingNodes.pop();
                if (itr != nullptr)
                {
                    std::cout << "Checkpoint 3" << std::endl;
                    returnVals.push_back(itr->val);
                    itr = itr->right;
                }
            }
            std::cout << "Checkpoint 4" << std::endl;
        } while(itr != nullptr || !pendingNodes.empty());
        return returnVals;
    }
};