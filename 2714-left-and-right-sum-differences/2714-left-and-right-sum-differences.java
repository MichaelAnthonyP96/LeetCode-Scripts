class Solution {
    public int[] leftRightDifference(int[] nums) {
        int size = nums.length;
        int[] leftSum = new int[size];
        int[] rightSum = new int[size];
        int[] answer = new int[size];
        leftSum[0] = 0;
        rightSum[size-1] = 0;

        // generate the leftSum array
        for (int idx = 1; idx < size; ++idx){
            leftSum[idx] = nums[idx-1] + leftSum[idx-1];
        }

        // generate the rightSum array
        for (int idx = size-2; idx >= 0; --idx){
            rightSum[idx] = nums[idx+1] + rightSum[idx + 1];
        }

        for (int idx = 0; idx < size; ++idx) {
            answer[idx] = Math.abs(leftSum[idx] - rightSum[idx]);
        }
        
        return answer;
    }
}