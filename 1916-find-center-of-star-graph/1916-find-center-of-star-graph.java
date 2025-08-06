class Solution {
    public int findCenter(int[][] edges) {

        // any two edges must be connected to the center, find the center and return
        if (edges[0][0] == edges[1][0]) {
            return edges[0][0];
        } else if (edges[0][1] == edges[1][0]) {
            return edges[0][1];
        } else if (edges[0][0] == edges[1][1]) {
            return edges[0][0];
        } else {
            return edges[0][1];
        }
    }
}