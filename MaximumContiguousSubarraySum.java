class Solution {
    public int maxSubArray(int[] nums) {\
        //check for an empty array
        if(nums.length == 0) return 0;
        //initialize maximum to the first term in nums
        int max = nums[0];
        //iterate through nums, summing in place only if the previous term is positive
        for(int i = 1; i < nums.length; i++){
            if(nums[i-1] > 0) nums[i] = nums[i] + nums[i-1];
            //use built in function to iteratively update the maximum
            max = Math.max(max, nums[i]);
        }
    //return the sum of the maximum contiguous subarray sum 
    return max;
    }
}