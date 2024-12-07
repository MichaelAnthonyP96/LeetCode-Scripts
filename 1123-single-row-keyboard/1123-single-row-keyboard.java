class Solution {
    HashMap<Character, Integer> map = new HashMap<>();
    public int calculateTime(String keyboard, String word) {

        // build the character mapping
        for (int i = 0; i < keyboard.length(); ++i) {
            map.put(keyboard.charAt(i), i);
        }

        // move through the string, summing the keyboard distance between adjacent chars
        int sum = map.get(word.charAt(0));
        for (int i = 1; i < word.length(); ++i) {
            sum += Math.abs(map.get(word.charAt(i)) - map.get(word.charAt(i-1)));
        }

        return sum;
    }
}