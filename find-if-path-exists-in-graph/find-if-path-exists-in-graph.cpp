class Solution {
public:
    class Graph
    {
        public:
            Graph(int size) : V(size)
            {
                adj = new std::list<int>[V];
            }
        
            void addEdge(int src, int dest)
            {
                // bi-directional edges
                adj[src].push_back(dest);
                adj[dest].push_back(src);
            }
            bool DFS(int src, int dst)
            {
                std::stack<int> s;
                bool visited[V];
                std::fill(visited, visited + V, false);
                
                // mark the starting node as visited and add to the stack
                visited[src] = true;
                s.push(src);
                while (!s.empty())
                {
                    int curr = s.top();
                    s.pop();
                    if (curr == dst)
                    {
                        return true;
                    }
                    else
                    {
                        for (auto& neighbor : adj[curr])
                        {
                            if (!visited[neighbor])
                            {
                                s.push(neighbor);
                            }
                        }
                    }
                    visited[curr] = true;
                }
                return false;
            }
        private:
            int V;
            std::list<int>* adj;
        
    };
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) 
    {
        Graph g(n);
        for (auto& edge : edges)
        {
            g.addEdge(edge[0], edge[1]);
        }
        
        return g.DFS(start, end);
        
        
    }
};