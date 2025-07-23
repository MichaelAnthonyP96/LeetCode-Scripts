class Solution {
    public int minBitFlips(int start, int goal) {
        int mask = start ^ goal;

        int count = 0;
        while (mask > 0) {
            count += mask & 1;
            mask >>= 1;
        }

        return count;
    }
}