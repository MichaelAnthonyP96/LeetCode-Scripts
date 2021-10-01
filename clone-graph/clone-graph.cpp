/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if (node == nullptr)
        {
            return node;
        }
        
        if (visited.count(node->val) > 0)
        {
            return visited[node->val];
        }
        
        // we need to create a new node 
        Node* clone = new Node(node->val);
        // insert it into the map
        visited.insert({node->val, clone});
        
        for (Node* neighbor : node->neighbors)
        {        
            // since this is a DAG, we need to add the edge in both directions
            // recurse through the neighbor's neighbors
            Node* result = cloneGraph(neighbor);
            clone->neighbors.push_back(result);
            // result->neighbors.push_back(clone);
        }
        
        return clone;
    }
private:
    std::unordered_map<int, Node*> visited;
};