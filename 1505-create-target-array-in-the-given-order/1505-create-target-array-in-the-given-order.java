class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        int n = nums.length;
        ArrayList<Integer> result = new ArrayList<>(n);

        for (int i = 0; i < n; ++i) {
            result.add(index[i], nums[i]);
        }

        return result.stream()
                .mapToInt(Integer::intValue) // or i -> i
                .toArray();
    }
}