class Solution {
    public long maxKelements(int[] nums, int k) {
        int n = nums.length;
        Queue<Integer> q = new PriorityQueue<>(n, Comparator.reverseOrder());

        for (int i = 0; i < n; ++i) {
            q.add(nums[i]);
        }

        long maxScore = 0;
        for (int j = 0; j < k; ++j) {
            int maxElem = q.poll();
            maxScore += maxElem;
            q.add((int) Math.ceil(maxElem / 3.));
        }
        
        return maxScore;
    }
}