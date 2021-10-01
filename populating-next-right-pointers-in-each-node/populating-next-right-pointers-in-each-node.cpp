/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        // perfrom BFS - level order traversal to assign the next pointers
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int levelSize = q.size();
            Node* currNode = nullptr;
            for (int i = 0; i < levelSize; ++i)
            {
                currNode = q.front();
                q.pop();
                if (i < levelSize - 1)
                {
                    currNode->next = q.front();
                }
                else
                {
                    currNode->next = nullptr;
                }
                if (currNode->left)
                {
                    q.push(currNode->left); 
                }
                if (currNode->right)
                {
                    q.push(currNode->right);
                }
            }
        }
        return root;
    }
};