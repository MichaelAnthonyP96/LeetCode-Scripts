class Solution {
    public int countPairs(List<Integer> nums, int target) {
        Collections.sort(nums); // Sort the list
        int count = 0;
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            if (nums.get(left) + nums.get(right) < target) {
                // All elements from left+1 to right will form valid pairs with left
                count += (right - left);
                left++;
            } else {
                right--;
            }
        }

        return count;
    }
}