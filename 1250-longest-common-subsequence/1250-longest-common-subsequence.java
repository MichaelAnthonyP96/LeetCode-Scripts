class Solution {
    private int[][] memo;
    private String text1;
    private String text2;

    public int longestCommonSubsequence(String text1, String text2) {
        memo = new int[text1.length() + 1][text2.length() +1];
        this.text1 = text1;
        this.text2 = text2;

        for (int i = 0; i < text1.length(); ++i) {
            for (int j = 0; j < text2.length(); ++j) {
                this.memo[i][j] = -1;
            }
        }

        return memoSolve(0,0);
    }

    public int memoSolve(int p1, int p2) {
        // return the already computed value if present.
        // values past the length of the string are set to 0
        if (memo[p1][p2] != -1) {
            return memo[p1][p2];
        }

        int answer = 0;
        if (text1.charAt(p1) == text2.charAt(p2)) {
            answer = 1 + memoSolve(p1 + 1, p2 + 1);
        } else {
            answer = Math.max(memoSolve(p1 + 1, p2), memoSolve(p1, p2+1));
        }
        
        // add the best answer to the memo
        memo[p1][p2] = answer;
        return answer;
    }
}