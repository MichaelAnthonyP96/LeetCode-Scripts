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
            if (matrix[i][0] == target)
            {
                return true;
            }
            // if the next item down the column is larger than the target, we know the value must be in this row
            if (i+1 < matrix.size())
            {
                if (target < matrix[i+1][0])
                {
                    // binary search the row
                    return std::binary_search(matrix[i].begin(), matrix[i].end(), target);    
                }
            }
            else
            {
                return std::binary_search(matrix[i].begin(), matrix[i].end(), target);
            }
            ++i;
        }
        return false;
    }
};