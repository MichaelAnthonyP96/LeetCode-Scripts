class Solution {
    public int balancedStringSplit(String s) {
        int ans = 0;
        Deque<Character> stack = new ArrayDeque<>();

        for (char c : s.toCharArray()) {
            if (!stack.isEmpty() &&
                (stack.peek() == 'R' && c == 'L' ||
                stack.peek() == 'L' && c == 'R')
                ) {
                stack.pop();
            } else {
                stack.push(c);
            }

            if (stack.isEmpty()) {
                ++ans;
            }
        }

        return ans;
    }
}