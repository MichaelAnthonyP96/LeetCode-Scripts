class Solution {
public:
    int factorial(int n)
    {
        return ((n + 1) * n) / 2;
    }
    
    int countLetters(string s) {
        // add a sentinel value to the end of the string
        s.append("!");
        int n = s.length();
        // consider the trivial cases
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int idx = 0;
        int count = 0;
        // iterate through the string, comparing each character with its previous
        for (int i = 1; i < n; ++i)
        {
            if (s[i] != s[i-1])
            {
                count += factorial(i - idx);
                idx = i;
            }
        }
        return count;
    }
};
