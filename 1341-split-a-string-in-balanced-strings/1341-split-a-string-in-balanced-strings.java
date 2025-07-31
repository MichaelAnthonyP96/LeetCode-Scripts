class Solution {
    public int balancedStringSplit(String s) {
        int ans = 0;
        Deque<Character> stack = new ArrayDeque<>();

        for (char c : s.toCharArray()) {
            if (!stack.isEmpty() &&
                (c == 'L' && stack.peek() == 'R' ||
                 c == 'R' && stack.peek() == 'L')) {
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