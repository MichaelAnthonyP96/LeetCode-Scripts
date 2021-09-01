class Solution {
public:
    std::pair<int, int> findNext(vector<vector<bool>>& visited_, vector<vector<char>>& grid)
    {
        for (int i = 0; i < visited_.size(); ++i)
        {
            for (int j = 0; j < visited_[i].size(); ++j)
            {
                // if the grid position has not been visited, inspect it
                if (!visited_[i][j])
                {
                    // if we found land that has not been visited, return it
                    if (grid[i][j] == '1')
                    {
                        return std::make_pair(i, j);
                    }
                    else
                    {
                        // otherwise mark '0' positions as visited as we go
                        visited_[i][j] = true;
                    }
                }
            }
        }
        return std::make_pair(-1, -1);
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int answer = 0;
        std::vector<std::vector<bool>> visited;
        for (int i = 0; i < grid.size(); ++i)
        {
            std::vector<bool> tmp(grid[i].size(), false);
            visited.push_back(tmp);
        }
        
        auto currLand = findNext(visited, grid);
        while (std::get<0>(currLand) != -1)
        {
            // perform DFS on this node that we have found to be solid land
            std::stack<std::pair<int, int>> s;
            s.push(currLand);
            while (!s.empty())
            {
                currLand = s.top();
                s.pop();
                auto i = std::get<0>(currLand);
                auto j = std::get<1>(currLand);
                // check the land to the right
                if (i+1 < grid.size() && grid[i+1][j] == '1' && !visited[i+1][j])
                {
                    s.push(std::make_pair(i+1, j));
                }
                // check the land to the left
                if (i-1 >= 0 && grid[i-1][j] == '1' && !visited[i-1][j])
                {
                    s.push(std::make_pair(i-1, j));
                }
                // check the land to above
                if (j+1 < grid[i].size() && grid[i][j+1] == '1' && !visited[i][j+1])
                {
                    s.push(std::make_pair(i, j+1));
                }
                // check the land to below
                if (j-1 >= 0 && grid[i][j-1] == '1' && !visited[i][j-1])
                {
                    s.push(std::make_pair(i, j-1));
                }
                visited[i][j] = true;
            }
            // we have exhausted all posibilities with this landmass, increase the island count and
            // find the next piece of land to search
            ++answer;
            currLand = findNext(visited, grid);
        }
        return answer;
    }
};