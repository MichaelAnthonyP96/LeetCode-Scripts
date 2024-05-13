class Solution {
    public String removeStars(String s) {
        Stack<Character> stack = new Stack<>();

        for (char c: s.toCharArray()) {
            if (c == '*') {
                stack.pop();
            } else {
                stack.push(c);
            }
        }

        StringBuilder answer = new StringBuilder();
        while(!stack.isEmpty()) {
            answer.append(stack.pop());
        }
        return answer.reverse().toString();
    }
}