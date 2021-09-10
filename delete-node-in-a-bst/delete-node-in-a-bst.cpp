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
    void clear(TreeNode* curr)
    {
        if (curr == nullptr)
        {
            return;
        }
        curr->left = nullptr;
        curr->right = nullptr;
    }
    
    TreeNode* findMin(TreeNode* curr)
    {
        if (curr == nullptr)
        {
            return nullptr;
        }
        while(curr->left)
        {
            curr = curr->left;
        }
        return curr;
    }
    
    TreeNode* findMax(TreeNode* curr)
    {
        if (curr == nullptr)
        {
            return nullptr;
        }
        while(curr->right)
        {
            curr = curr->right;
        }
        return curr;
    }
    
    bool deleteNodeHelper(TreeNode*& curr, TreeNode* parent, int key)
    {
        if (curr == nullptr)
        {
            return false;
        }
        if (key < curr->val && curr->left != nullptr)
        {
            // keep search left
            return deleteNodeHelper(curr->left, curr, key);
        }
        else if (key < curr->val)
        {
            // we didn't find our key
            return false;
        }
        else if (key > curr->val && curr->right != nullptr)
        {
            // keep searching right
            return deleteNodeHelper(curr->right, curr, key);
        }
        else if (key > curr->val)
        {
            // we didn't find our key
            return false;
        }
        else
        {
            if (parent == nullptr)
            {
                // we are the root of the tree and therefore have no parent
                if (curr->right)
                {
                    // if we have a right subtree, find the min
                    TreeNode* predecessor = findMin(curr->right);
                    curr->val = predecessor->val;
                    // now we delete that node (which is now a duplicate), from the right subtree
                    deleteNodeHelper(curr->right, curr, curr->val);
                }
                else if (curr->left)
                {
                    // if we have a left subtree, find the max
                    TreeNode* predecessor = findMax(curr->left);
                    curr->val = predecessor->val;
                    // now we delete that node (which is now a duplicate), from the right subtree
                    deleteNodeHelper(curr->left, curr, curr->val);
                }
                else
                {
                    // if we have no children and are the root, simply clear ourself
                    clear(curr);
                    curr = nullptr;
                    return true;
                }
                
            }
            else if (curr->left == nullptr && curr->right == nullptr && curr == parent->left)
            {
                // No children, we are the left child of our parent
                TreeNode* tmp = curr;
                parent->left = nullptr;
                clear(tmp);
                delete tmp;
            }
            else if (curr->left == nullptr && curr->right == nullptr && curr == parent->right)
            {
                // No children, we are the right child of our parent
                TreeNode* tmp = curr;
                parent->right = nullptr;
                clear(tmp);
                delete tmp;
            }
            else if (curr->left != nullptr && curr->right == nullptr && curr == parent->left)
            {
                // We have one left child, we are the left of our parent
                TreeNode* tmp = curr;
                parent->left = curr->left;
                clear(tmp);
                delete tmp;
            }
            else if (curr->left == nullptr && curr->right != nullptr && curr == parent->right)
            {
                // we have one right child, we are the right child of our parent
                TreeNode* tmp = curr;
                parent->right = curr->right;
                clear(tmp);
                delete tmp;
            }
            else if (curr->left != nullptr && curr->right == nullptr && curr == parent->right)
            {
                // we have one left child, we are the right child of our parent
                TreeNode* tmp = curr;
                parent->right = curr->left;
                clear(tmp);
                delete tmp;
            }
            else if (curr->left == nullptr && curr->right != nullptr && curr == parent->left)
            {
                // we have one right child, we are the left child of our parent
                TreeNode* tmp = curr;
                parent->left = curr->right;
                clear(tmp);
                delete tmp;
            }
            else
            {
                // we have two children, we need to swap our value with the in order predecessor
                // this means the smallest value in the right subtree, or the largest value in 
                // the left subtree. We arbitrarily pick the min in the right subtree
                TreeNode* predecessor = findMin(curr->right);
                curr->val = predecessor->val;
                // now we delete that node (which is now a duplicate), from the right subtree
                deleteNodeHelper(curr->right, curr, curr->val);
            }
        }
        return true;
        
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (key < root->val)
        {
            deleteNodeHelper(root->left, root, key);
            return root;
        }
        else if (key > root->val)
        {
            deleteNodeHelper(root->right, root, key);
            return root;
        }
        else
        {
            // the root is the key we want to delete, oh boy
            deleteNodeHelper(root, nullptr, key);
            return root;
        }
    }
};