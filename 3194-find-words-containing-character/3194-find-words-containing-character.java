class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        int idx = 0;
        List<Integer> result = new ArrayList<>();
        CharSequence cs = String.valueOf(x);
        for (String word: words) {
            if (word.contains(cs)) {
                result.add(idx);
            }
            idx++;
        }
        
        return result;
    }
}