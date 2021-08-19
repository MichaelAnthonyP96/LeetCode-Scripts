class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // We start at the bottom left and move up and to the right
        int rowSize = matrix.size();
        int columnSize = matrix[0].size();
        int i = rowSize ? rowSize - 1 : 0;
        int j = 0;
        while (i >= 0 && j < columnSize)
        {
            if (matrix[i][j] < target)
            {
                // move one column to the right, since all values to the right right in this row are larger
                ++j;
            }
            else if (matrix[i][j] > target)
            {
                // move one row up, since we know all values above in this column should be smaller
                --i;
            }
            else
            {
                return true;
            }
        }
        // we didn't find our target value 
        return false;
    }
};