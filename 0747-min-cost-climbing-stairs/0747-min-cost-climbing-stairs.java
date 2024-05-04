class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int[] runningCosts = new int[cost.length];
        
        // base cases
        runningCosts[0] = cost[0];
        runningCosts[1] = cost[1];
        
        for (int i = 2; i < cost.length; ++i) {
            runningCosts[i] = cost[i] + Math.min(runningCosts[i-1], runningCosts[i-2]);
        }
        return Math.min(runningCosts[cost.length-1], runningCosts[cost.length-2]);
    }
}