class Solution {
public:
    class Graph
    {
        static int WHITE;
        static int GRAY;
        static int BLACK;
        
        public:
            Graph (int v) : V(v), colors(), cycleDetected(false)
            {
                adjacent = new std::list<int>[V];
                // Assign WHITE to all the nodes to start
                for (int i = 0; i < v; ++i)
                {
                    colors.insert({i, WHITE});
                }
            }
            void addEdge(int u, int v)
            {
                // add edge from u to v
                adjacent[u].push_back(v);
            }
            std::vector<int> topoSort()
            {
                std::stack<int> s;
                
                bool* visited = new bool[V];
                std::fill(visited, visited + V, false);
                
                for (int i = 0; i < V; ++i)
                {
                    if (!visited[i])
                    {
                        // if this node hasn't been visited, investigate it
                        topoSortHelper(i, visited, s);
                    }
                }
                
                std::vector<int> returnVals;
                while (!s.empty())
                {
                    returnVals.push_back(s.top());
                    s.pop();
                }
                return returnVals;
            }
        bool cycleDetected {false};
        private:
            int V {0}; // number of vertices
            std::list<int>* adjacent; // Adjacency lists
            std::map<int, int> colors;// dictionary representing node colors
            
            void topoSortHelper(int v, bool visited[], std::stack<int>& stack)
            {
                visited[v] = true;
                colors[v] = GRAY;
                
                // make sure to investigate all nodes before pushing ourself to the stack
                for (auto i = adjacent[v].begin(); i != adjacent[v].end(); ++i)
                {
                    int currColor = colors[*i];
                    if (GRAY == currColor)
                    {
                        cycleDetected = true;
                        return;
                    }
                    else if (!visited[*i])
                    {
                        
                        if (WHITE == currColor)
                        {
                            topoSortHelper(*i, visited, stack);
                        }
                        
                    }
                }
                
                // recursion ends, so we mark the node as black
                colors[v] = BLACK;
                stack.push(v);
            }
    };
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        Graph g(numCourses);
        
        for (auto& pair : prerequisites)
        {
            g.addEdge(pair[1], pair[0]);
        }
        
        auto result = g.topoSort();
        if (!g.cycleDetected)
        {
            return result;
        }
        else
        {
            return std::vector<int>();    
        }
    }
};

int Solution::Graph::WHITE = 1;
int Solution::Graph::GRAY = 2;
int Solution::Graph::BLACK = 3;