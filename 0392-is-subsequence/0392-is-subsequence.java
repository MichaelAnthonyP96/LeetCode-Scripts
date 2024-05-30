class Solution {
    public boolean isSubsequence(String s, String t) {
        int idx = -1 ;
        for (char c : s.toCharArray()) {
            int nextIdx = t.indexOf(c, idx + 1);
            if (nextIdx > idx) {
                idx = nextIdx;
            } else if (nextIdx == -1) {
                return false;
            }
        }
        
        return true;
    }
}