class Solution {
    public int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;

        while (n > 0) {
            int trailingDigit = n % 10;
            product *= trailingDigit;
            sum += trailingDigit;
            n /= 10;
        }
        
        return product - sum;
    }
}