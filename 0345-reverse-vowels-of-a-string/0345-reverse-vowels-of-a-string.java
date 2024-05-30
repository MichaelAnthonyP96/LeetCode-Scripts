class Solution {
    public String reverseVowels(String s) {
        Queue<Character> queue = new ArrayDeque<Character>();
        char[] charArray = s.toCharArray();

        for (int i = 0; i < s.length(); ++i) {
            char c = charArray[i];
            if (isAVowel(c)) {
                queue.add(c);
            }
        }

        for (int i = s.length() - 1; i >= 0; --i) {
            char c = charArray[i];
            if (isAVowel(c)) {
                charArray[i] = queue.poll();
            }
        }
        return new String(charArray);
    }

    boolean isAVowel(char c) {
        return c == 'a' || c == 'A' ||
                c == 'e' || c == 'E' ||
                c == 'i' || c == 'I' ||
                c == 'o' || c == 'O' ||
                c == 'u' || c == 'U';
    }
}