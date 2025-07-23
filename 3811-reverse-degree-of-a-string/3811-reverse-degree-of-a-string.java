class Solution {
    public int reverseDegree(String s) {
        int reverseDegree = 0;
        int pos = 1;
        for (char c : s.toCharArray()) {
            reverseDegree += (pos * (('a' - c) + 26));
            pos++;
        }

        return reverseDegree;
    }
}