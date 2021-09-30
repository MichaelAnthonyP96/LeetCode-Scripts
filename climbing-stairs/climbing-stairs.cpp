class Solution {
public:
    int climbStairs(int n) 
    {
        
        if (n <= 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }
        std::vector<int> stairs(n, -1);
        
        stairs[0] = 1;
        stairs[1] = 2;
        
        for (int i = 2; i < n; ++i)
        {
            stairs[i] = stairs[i-1] + stairs[i-2];
        }
        
        return stairs[n-1];
    }
};