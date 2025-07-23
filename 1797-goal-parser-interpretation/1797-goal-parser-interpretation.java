class Solution {
    public String interpret(String command) {
        StringBuilder builder = new StringBuilder(command.length());
        for (int i = 0; i < command.length(); ++i) {
            if (command.charAt(i) == 'G') {
                builder.append('G');
            } else if (command.charAt(i) == '(') {
                if (command.charAt(i+1) == ')') {
                    builder.append('o');
                } else if (command.charAt(i+1) == 'a') {
                    builder.append("al");
                }
                ++i;
            }
        }

        return builder.toString();
    }
}