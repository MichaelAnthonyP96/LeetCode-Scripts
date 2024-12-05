class Solution {
    public int[][] largestLocal(int[][] grid) {
        int n = grid.length;
        int[][] result = new int[n-2][n-2];

        for (int i = 1; i < (n-1); ++i) {
            for (int j = 1; j < (n-1); ++j) {
                result[i -1][j - 1] = max(i, j, grid);
            }
        }

        return result;
    }

    int max(int i, int j, int[][] grid) {
        int max = 0;
        for (int I = i-1; I < (i + 2); ++I) {
            for (int J = j-1; J < (j + 2); ++J) {
                max = Math.max(max, grid[I][J]);
            }
        }

        return max;
    }
}