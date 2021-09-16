#include <math.h>
class Solution {
public:
    int mySqrt(int x) 
    {
        if (x < 2)
            return x;
        
        unsigned long left = 2;
        unsigned long right = (x / 2);
        unsigned long mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            long double result = mid * mid;
            if (result > x)
            {
                right = mid - 1;
            }
            else if (result < x)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return right;
    }
};