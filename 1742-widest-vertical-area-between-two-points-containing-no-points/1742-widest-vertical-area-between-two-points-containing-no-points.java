class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        Arrays.sort(points, (row1, row2) -> Integer.compare(row1[0], row2[0]));

        int maxWidth = 0;
        for (int idx = 0; idx < (points.length - 1); ++idx) {
            maxWidth = Math.max(maxWidth, points[idx+1][0] - points[idx][0]);
        }

        return maxWidth;
    }
}