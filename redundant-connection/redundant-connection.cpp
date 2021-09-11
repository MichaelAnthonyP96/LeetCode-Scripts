class Solution {
public:
    class Graph
    {
        public:
            Graph(int v) : V(v+1)
            {
                adjList.resize(V);
                visited.resize(V);
                std::fill(visited.begin(), visited.end(), false);
            }
            void addEdge(int u, int v)
            {
                // add an edge from u to v
                adjList[u].push_back(v);
                // add an edge from v to u 
                adjList[v].push_back(u);
            }
        
            bool DFS(int source, int dest)
            {
                
                if (!visited[source])
                {
                    
                    visited[source] = true;
                    if (source == dest) return true;
                    for (int neighbor : adjList[source])
                    {
                        if (DFS(neighbor, dest)) return true;
                    }
                }
                return false;
            }
            std::vector<std::vector<int>> adjList;
            std::vector<bool> visited;
            int V; // number of nodes
    };
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        Graph g(edges.size());
        for (auto pair : edges)
        {
            std::fill(g.visited.begin(), g.visited.end(), false);
            if (!g.adjList[pair[0]].empty() && 
                !g.adjList[pair[1]].empty() &&
                g.DFS(pair[0], pair[1]))
            {
                return pair;
            }
            else
            {
               g.addEdge(pair[0], pair[1]); 
            }
        }

        return std::vector<int>();
        
    }
};