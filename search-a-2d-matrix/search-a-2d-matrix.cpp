#include <algorithm>
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // if the target is smaller than the smallest possible value in the matrix, we know it can't exist
        if (target < matrix[0][0])
        {
            return false;
        }
        int i = 0;
        // iterate down the first column
        while ((i < matrix.size()) && target >= matrix[i][0])
        {
            // if the start of the row is equal to the target, we are done
            if (matrix[i][0] == target)
            {
                return true;
            }
            
            // if the next row is still valid
            if (i+1 < matrix.size())
            {
                // if the next item down the column is larger than the target, we know the value must be in this row
                if (target < matrix[i+1][0])
                {
                    // binary search the row
                    return std::binary_search(matrix[i].begin(), matrix[i].end(), target);    
                }
            }
            else
            {
                // we've hit the last row, search it anyway
                return std::binary_search(matrix[i].begin(), matrix[i].end(), target);
            }
            ++i;
        }
        return false;
    }
};
