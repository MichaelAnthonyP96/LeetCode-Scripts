class Solution {
    public int maxAscendingSum(int[] nums) {
        int leftPtr = 0;
        int rightPtr = 1;
        int size = nums.length;
        int currMax = nums[0];
        int max = currMax;
        while(rightPtr < size) {
            if (nums[leftPtr] < nums[rightPtr]) {
                currMax += nums[rightPtr++];
                leftPtr++;
                max = Math.max(currMax, max);
            } else {
                max = Math.max(currMax, max);
                leftPtr = rightPtr++;
                currMax = nums[leftPtr];
            }
        }
        
        return max;
    }
}