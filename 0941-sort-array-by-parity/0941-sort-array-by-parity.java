class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int even = 0;
        int odd = nums.length -1;
        
        while (even < odd) {
            if (nums[even] % 2 == 0) {
                // this is an even number and should be skipped
                ++even;
                continue;
            } else if (nums[odd] % 2 == 1) {
                --odd;
                continue;
            } else {
                swap(even, odd, nums);
            }
        }
        return nums;
    }
    
    public void swap(int i, int j, int[] nums) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}