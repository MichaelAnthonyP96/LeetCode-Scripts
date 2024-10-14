class Solution {
    Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u');

    public String removeVowels(String s) {
        StringBuilder sb = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (!vowels.contains(c)) {
                sb.append(c);
            }
        }

        return sb.toString();
    }
}