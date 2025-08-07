class Solution {
    public int mostWordsFound(String[] sentences) {
        int max = 0;

        for (String s : sentences) {
            int currCount = 0;
            for (char c : s.toCharArray()) {
                if (c == ' ') {
                    currCount++;
                }
            }
            max = Math.max(max, currCount + 1);
        }

        return max;
    }
}