class Solution {
    public void sortColors(int[] nums) {
        if (nums.length == 1) return;
        int leftIndex = 0;
        int rightIndex = nums.length - 1;
        int curr = 0;
        while(curr <= rightIndex) {
            if (nums[curr] == 0) {
                swap(curr, leftIndex, nums);
                leftIndex++;
                curr++;
            }
            else if (nums[curr] == 2) {
                // swap the min we found with the current value
                swap(curr, rightIndex, nums);
                rightIndex--;
            } else {
                ++curr;
            }
        }       
    }
    
    public void swap(int i, int j, int[] nums){
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }
}