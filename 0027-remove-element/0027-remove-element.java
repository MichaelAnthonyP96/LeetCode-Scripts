class Solution {
    public int removeElement(int[] nums, int val) {
        int swapPos = findLastNonVal(nums, val, nums.length-1);
        for (int i = 0; i < swapPos; ++i) {
            if (nums[i] == val) {
                // swap the target number with a nonVal at the end of the list
                swap(nums, swapPos, i);
                // find the next swapPosition
                swapPos = findLastNonVal(nums, val, swapPos);
            }
        }
        return (swapPos + 1);
    }
    
    public void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    public int findLastNonVal(int nums[], int val, int start) {
        for (int j = start; j >= 0; --j) {
            if (nums[j] != val) {
                return j;
            }       
        }
        // we didn't find a value to swap
        return -1;
    }
}