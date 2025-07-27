class Solution {
    public boolean isPalindrome(String s) {
        // trim whitespace and convert to lowercase
        s = s.trim().toLowerCase();
        StringBuilder builder = new StringBuilder();

        // extract any non-characters
        for (char c : s.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                builder.append(c);
            }
        }

        Stack<Character> stack = new Stack<>();
        String lettersOnlyString = builder.toString();
        boolean isEven = (lettersOnlyString.length() % 2 == 0);
        // add the first half of the letters to the stack
        for (int idx = 0; idx < (lettersOnlyString.length() / 2); ++idx) {
            stack.add(lettersOnlyString.charAt(idx));
        }

        // compare the second half of the letters with the stack
        int start = isEven ? (lettersOnlyString.length() / 2) : ((lettersOnlyString.length() / 2) + 1);
        for (int idx = start; idx < lettersOnlyString.length(); ++idx) {
            if (stack.pop() != lettersOnlyString.charAt(idx)){
                return false;
            }
        }

        return stack.isEmpty();
    }
}