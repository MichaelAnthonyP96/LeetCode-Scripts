class Solution {
    public int[] minOperations(String boxes) {
        ArrayList<Integer> ballPositions = new ArrayList<>();
        int[] result = new int[boxes.length()];

        int position = 0;
        for (char c : boxes.toCharArray()) {
            if (c == '1') {
                ballPositions.add(position);
            }
            ++position;
        }

        int initialPos = 0;
        for (int i = 0; i < boxes.length(); ++i) {
            for (Integer j : ballPositions) {
                result[i] += Math.abs(i - j);
            }
        }

        return result;
    }
}