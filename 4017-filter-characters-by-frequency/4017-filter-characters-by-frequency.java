class Solution {
    public String filterCharacters(String s, int k) {
        int[] charMap = new int[26];

        for (char c : s.toCharArray()) {
            charMap[c - 'a']++;
        }

        StringBuilder builder = new StringBuilder(s.length());
        for (char c : s.toCharArray()) {
            if (charMap[c - 'a'] < k) {
                builder.append(c);
            }
        }

        return builder.toString();
    }
}