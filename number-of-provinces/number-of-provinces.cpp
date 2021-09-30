class Solution {
public:
    class UnionFind
    {
        public:
            UnionFind(int size) : root(size), rank(size, 1)
            {
                for (int i = 0; i < size; ++i)
                {
                    root[i] = i;
                }
            }
        
            bool Connected(int x, int y)
            {
                return Find(x) == Find(y);
            }

            int Find(int x)
            {
                if (x == root[x])
                {
                    return x;
                }
                else
                {
                    root[x] = Find(root[x]);
                }
                return root[x];
            }

            void Union(int x, int y)
            {
                int xParent = Find(x);
                int yParent = Find(y);
                if (rank[xParent] > rank[yParent])
                {
                    root[yParent] = xParent;
                }
                else if (rank[yParent] > rank[xParent])
                {
                    root[xParent] = yParent;
                }
                else
                {
                    root[yParent] = xParent;
                    rank[xParent] += 1;
                }
            }
        private:
        std::vector<int> root;
        std::vector<int> rank;
    };
    
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int size = isConnected.size();
        UnionFind u(size);
        int numProvinces = size;
        for (int row = 0; row < size; ++row)
        {
            for (int col = 0; col <= row; ++col)
            {
                if (isConnected[row][col] && !u.Connected(row, col))
                {
                    u.Union(row, col);
                    --numProvinces;
                }
            }
        }
        return numProvinces;
    }
};