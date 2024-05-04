class Solution {
    public int rob(int[] nums) {
        // edge case
        if (nums.length == 1) {
            return nums[0];
        }
        int[] dp = new int[nums.length];

        // base cases
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);

        // iterate over the remaining houses, considering the max of the previous house
        // or the current house plus the value of two houses ago
        for (int i = 2; i < nums.length; ++i){
            dp[i] = Math.max(dp[i-1], nums[i] + dp[i-2]);
        }

        return dp[nums.length-1];
    }
}