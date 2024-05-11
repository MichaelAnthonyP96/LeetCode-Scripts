class Solution {
    public int removeDuplicates(int[] nums) {
        // The first element is always unique
        int insertIdx = 1;
        for (int i = 0; i < (nums.length - 1); ++i) {
            // if the next
            if (nums[i+1] != nums[i]) {
                // count the number of current repeats
                nums[insertIdx++] = nums[i+1];
                
            }
        }
        return insertIdx;
    }
}