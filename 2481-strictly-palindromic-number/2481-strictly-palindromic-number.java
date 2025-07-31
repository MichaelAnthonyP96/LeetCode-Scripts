class Solution {
    public boolean isStrictlyPalindromic(int n) {

        for(int b = 2; b < n - 1; ++b) {
            String s = generateBinaryRepresentation(b, n);
            if (!isValidPalindrome(s)) {
                return false;
            }
        }
        
        return true;
    }

    public String generateBinaryRepresentation(int base, int n) {
        StringBuilder builder = new StringBuilder();

        while(n > 0) {
            builder.append(n % base);
            n /= base;
        }

        return builder.toString();
    }

    public boolean isValidPalindrome(String s) {
        int leftPtr = 0;
        int rightPtr = s.length() - 1;

        while (leftPtr <= rightPtr) {
            if (s.charAt(leftPtr++) != s.charAt(rightPtr--)) {
                return false;
            }
        }
        return true;
    }
}