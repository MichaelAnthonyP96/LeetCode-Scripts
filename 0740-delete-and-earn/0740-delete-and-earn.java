class Solution {
    HashMap<Integer, Integer> points = new HashMap<>();
    HashMap<Integer, Integer> cache = new HashMap<>();
    public int deleteAndEarn(int[] nums) {
        

        // count how many of each variable
        int maxValue = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; ++i) {
            points.compute(nums[i], (k, v) -> (v == null) ? 1 : v + 1);
            maxValue = Math.max(maxValue, nums[i]);
        }

        for (Map.Entry<Integer, Integer> e : points.entrySet()) {
            points.put(e.getKey(), e.getKey() * e.getValue());
        }
        
        return maxPoints(maxValue);
    }

    public int maxPoints(int num) {
        // Check for base cases
        if (num == 0) {
            return 0;
        }
        
        if (num == 1) {
            return points.getOrDefault(1, 0);
        }

        if (cache.containsKey(num)) {
            return cache.get(num);
        }
        
        // Apply recurrence relation
        int gain = points.getOrDefault(num, 0);
        cache.put(num, Math.max(maxPoints(num - 1), maxPoints(num - 2) + gain));
        return cache.get(num);
    }
}