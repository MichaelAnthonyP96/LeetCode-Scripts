class Solution {
    public int maxStudentsOnBench(int[][] students) {
        HashMap<Integer, Set<Integer>> map = new HashMap<>();

        for (int[] student : students) {
            if (!map.containsKey(student[1])) {
                Set<Integer> studentIds = new HashSet<>();
                studentIds.add(student[0]);
                map.put(student[1], studentIds);
            } else {
                Set<Integer> studentIds = map.get(student[1]);
                if (!studentIds.contains(student[0])) {
                    studentIds.add(student[0]);
                }
            }
        }

        int max = 0;
        for (Set<Integer> bench : map.values()) {
            max = Math.max(max, bench.size());
        }
        
        return max;
    }
}