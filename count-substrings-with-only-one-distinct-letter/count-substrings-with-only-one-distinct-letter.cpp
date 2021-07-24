class Solution {
public:
    int factorial(int a)
    {
        // if we find the factorial value in the map already, just return it
        if (factorialMap.find(a) != factorialMap.end())
        {
            return factorialMap.find(a)->second;
        }
        else
        {
            auto last = factorialMap.rbegin();
            for (auto itr = (last->first + 1); itr <= a; ++itr)
            {
                factorialMap.insert({itr, last->second + itr});
            }
        }
        return factorialMap.find(a)->second;
    }
    
    int countLetters(string s) {
        // first divide the string into subtrings on only distinct letters
        s.append("!");
        int n = s.length();
        // consider the trivial cases
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int idx = 0;
        int count = 0;
        for (int i = 1; i < n; ++i)
        {
            if (s[i] == s[i-1])
            {
                
            }
            else
            {
                count += factorial(i - idx);
                idx = i;
            }
        }
        return count;
    }
private:
    std::map<int, int> factorialMap{{1,1}, {2,3}, {3,6}, {4,10}};
};