class Solution {
    public void moveZeroes(int[] nums) {
        if (nums == null || nums.length == 1) {
            return;
        }
        
        
        int zeroIdx = findLeftmostZero(nums, 0);
        int nonZeroIdx = findNextNonZeroToTheRight(nums, zeroIdx);
        
        while ((zeroIdx < nonZeroIdx) && (nonZeroIdx != -1) && (zeroIdx != -1)) {
            swap(zeroIdx, nonZeroIdx, nums);
            zeroIdx = findLeftmostZero(nums, zeroIdx);
            nonZeroIdx = findNextNonZeroToTheRight(nums, zeroIdx);
        }
    }
    
    public int findLeftmostZero(int[] nums, int start) {
        if (start == -1) return -1;
        for (int i = start; i < nums.length; ++i) {
            if (nums[i] == 0){
                return i;
            }
        }
        // they are all non-zeros
        return -1;
    }
    
    public int findNextNonZeroToTheRight(int[] nums, int start) {
        if (start == -1) return -1;
        for (int i = start; i < nums.length; ++i) {
            if (nums[i] != 0) {
                return i;
            } 
        }
        // they are all zeros?
        return -1;
    }
    
    public void swap(int j, int k, int[] nums) {
        int tmp = nums[j];
        nums[j] = nums[k];
        nums[k] = tmp;
    }
}