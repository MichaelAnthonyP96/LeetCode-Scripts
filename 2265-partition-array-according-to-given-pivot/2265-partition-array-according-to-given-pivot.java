class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int less = 0;
        int equal = 0;
        int size = nums.length;
        int[] answer = new int[size];

        for (int idx = 0; idx < size; ++idx) {
            if (nums[idx] == pivot) {
                ++equal;
            } else if (nums[idx] < pivot) {
                ++less;
            }
        }

        int lessIdx = 0;
        int equalIdx = less;
        int greaterIdx = less + equal;

        for (int idx = 0; idx < size; ++idx) {
            if (nums[idx] == pivot) {
                answer[equalIdx++] = pivot;
            } else if (nums[idx] < pivot) {
                answer[lessIdx++] = nums[idx];
            } else {
                answer[greaterIdx++] = nums[idx];
            }
        }
        
        return answer;
    }
}