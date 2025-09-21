class Solution {
    public int[] recoverOrder(int[] order, int[] friends) {
        Set<Integer> raceIds = new HashSet<>();

        for (int friend : friends) {
            raceIds.add(friend);
        }

        int[] result = new int[friends.length];
        int pos = 0;
        for (int id : order) {
            if (raceIds.contains(id)) {
                result[pos++] = id;
            }
        }

        return result;
    }
}