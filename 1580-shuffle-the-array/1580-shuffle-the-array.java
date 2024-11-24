class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] result = new int[nums.length];
        int pos = 0;

        for (int i = 0; i < n; ++i) {
            result[pos++] = nums[i];
            result[pos++] = nums[i + n];
        }
        
        return result;
    }
}