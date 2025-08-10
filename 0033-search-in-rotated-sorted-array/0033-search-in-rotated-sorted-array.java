class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[n -1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        int answer = binarySearch(nums, 0 , left - 1, target);
        if (answer != -1) {
            return answer;
        }
        
        return binarySearch(nums, left,  n-1, target);
    }

    public int binarySearch(int[] nums, int left, int right, int target) {

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
}