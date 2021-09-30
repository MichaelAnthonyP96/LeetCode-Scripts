class Solution {
public:
    double myPow(double x, int n) 
    {
        return myPow(x, (long long)n);
    }
    
    double myPow(double x, long long n)
    {
        if (n == 0)
        {
            return 1;
        }
        else if (n < 0)
        {
            // flip the signs for negative numbers, simplifies the process
            x = 1 / x;
            n = -n;
        }
        
        double answer = 1;
        double currProduct = x;
        if (n % 2)
        {
            // if n is odd, reduce by one and
            answer *= currProduct;
            --n;
        }
        double result = myPow(x, n / 2);
        return answer * result * result;
    }
};