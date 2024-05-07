class Solution {
    public void sortColors(int[] nums) {
        int index = 0;
        int currMin = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; ++i) {
            // find the min value
            currMin = nums[i];
            for (int j = i + 1; j < nums.length; ++j){
                if (nums[j] < currMin) {
                    currMin = nums[j];
                    index = j;
                }
             }
            
            if (currMin < nums[i]) {
                // swap the min we found with the current value
                swap(i, index, nums);
            }
        }       
    }
    
    public void swap(int i, int j, int[] nums){
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }
}