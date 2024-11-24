class Solution {
    public int myAtoi(String s) {
        if (s.length() == 0) {
            return 0;
        }
        int result = 0;
        int start = 0;
        boolean positive = true;
        // trim whitespace
        s = s.trim();
        if (s.isEmpty()) {
            return 0;
        }


        // try to read the sign
        if (s.charAt(0) == '-') {
            positive = false;
            start = 1;
        } else if (s.charAt(0) == '+') {
            start = 1;
        }
        
        // if no present, assume positive
        for (int i = start; i < s.length(); ++i) {
            char c = s.charAt(i);
            int digit = Character.getNumericValue(c);
            if (c <= '9' && c >= '0') {
                // we know this is a number
                if ((Integer.MAX_VALUE / 10) < result ||
                (result == Integer.MAX_VALUE / 10 &&
                    digit > Integer.MAX_VALUE % 10)) {
                    if (positive) {
                        return Integer.MAX_VALUE;
                    } else {
                        return Integer.MIN_VALUE;
                    }
                }
                result *= 10;
                result += digit;
            } else {
                break;
            }
        }
        
        if (positive) return result;
        
        return -1 * result;
    }
}