#include <string>
class Solution {
public:
    int getSubGrid(int row, int column)
    {
        if (row <= 2)
        {
            if (column <= 2)
            {
                return 0;
            }
            else if (column <= 5)
            {
                return 1;
            }
            else if (column <= 8)
            {
                return 2;
            }
        }
        else if (row <= 5)
        {
            if (column <= 2)
            {
                return 3;
            }
            else if (column <= 5)
            {
                return 4;
            }
            else if (column <= 8)
            {
                return 5;
            }
        }
        else if (row <= 8)
        {
            if (column <= 2)
            {
                return 6;
            }
            else if (column <= 5)
            {
                return 7;
            }
            else if (column <= 8)
            {
                return 8;
            }
        }
        return -1;   
    }    
    
    
    
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        std::unordered_multimap<int, std::tuple<int, int, int>> m;
        
        for (int row = 0; row < 9; ++row)
        {
            for (int col = 0; col < 9; ++col)
            {
                char c = board[row][col];
                if ('.' == c)
                {
                    continue;
                }
                else
                {
                    int digit = c - '0';
                    int currSubGrid = getSubGrid(row, col);
                    if (m.count(digit) > 0)
                    {
                        for (auto itr = m.find(digit), end = m.end(); itr != end; ++itr)
                        {
                            if (itr->first != digit)
                            {
                                break;
                            }
                            if (std::get<0>(itr->second) == currSubGrid ||
                                std::get<1>(itr->second) == row ||
                                std::get<2>(itr->second) == col )
                            {
                                return false;
                            }
                        }
                        m.insert({digit, {currSubGrid, row, col}});
                    }
                    else
                    {
                        m.insert({digit, {currSubGrid, row, col}});
                    }
                }
            }
        }
        return true;
    }
};