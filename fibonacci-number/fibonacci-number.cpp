class Solution {
public:
    int fibHelper(int i, std::unordered_map<int, int>& m)
    {
        if (i == 0)
            return 0;
        if (i == 1)
            return 1;
        
        auto result1 = m.find(i-1);
        int one = 0;
        if (result1 != m.end())
        {
            one = result1->second;
        }
        else
        {
            one = fibHelper(i-1, m);
            m.insert({i-1, one});
        }
        
        auto result2 = m.find(i-2);
        int two = 0;
        if (result2 != m.end())
        {
            two = result2->second;
        }
        else
        {
            two = fibHelper(i-2, m);
            m.insert({i-2, two});
        }
        return one + two;
    }
    
    int fib(int n) 
    {
        std::unordered_map<int, int> m;
        m.insert({0, 0});
        m.insert({1, 1});
        return fibHelper(n, m);
    }
};