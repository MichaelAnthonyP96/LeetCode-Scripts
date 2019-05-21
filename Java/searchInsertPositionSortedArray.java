class Solution {
    public int searchInsert(int[] nums, int target) {
        //if the target is smaller than the first value, return 0
        if(nums[0] > target) return 0;
        //if the target is larger than the last value, return length
        if(nums[nums.length - 1] < target) return nums.length;
        //iterate over all the nums values since we know it belongs 
        //somewhere in the middle of the array
        for(int i = 0; i < nums.length; i++){
            //if the current nums value is equal to or larger than the target, 
            //return the current index because it belongs at this index
            if(nums[i] >= target) return i;
        }
    //this value indicates something is wrong
    return Integer.MIN_VALUE;
    }
}