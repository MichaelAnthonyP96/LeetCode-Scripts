class Solution {
    public int maxFreqSum(String s) {
        int[] frequency = new int[26];

        int vowelMax = 0;
        int consonantMax = 0;
        Set<Integer> vowelSet = Set.of('a' - 'a', 'e' - 'a', 'i' - 'a', 'o' - 'a', 'u' - 'a');
        for (char c : s.toCharArray()) {
            int position = c - 'a';
            ++frequency[position];
            if (vowelSet.contains(position)) {
                vowelMax = Math.max(frequency[position], vowelMax);
            } else {
                consonantMax = Math.max(frequency[position], consonantMax);
            }        }
        
        return vowelMax + consonantMax;
    }
}