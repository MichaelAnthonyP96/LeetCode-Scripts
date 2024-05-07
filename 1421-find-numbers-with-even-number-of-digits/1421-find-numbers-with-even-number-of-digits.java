class Solution {
    public int findNumbers(int[] nums) {
        int count = 0;
        for (int i = 0; i < nums.length; ++i) {
            int currentNum = nums[i];
            int digitCount = 0;
            while(currentNum > 0) {
                currentNum /= 10;
                digitCount += 1;
            }
            if (digitCount % 2 == 0) {
                count += 1;
            }
        }
        return count;
    }
}