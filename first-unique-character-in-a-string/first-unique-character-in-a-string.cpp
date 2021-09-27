class Solution {
public:
    int firstUniqChar(string s) {
        // count the number of occurrences of each letter in the word
        std::unordered_map<char, int> m;
        for (char& c : s)
        {
            if (m.count(c) > 0)
            {
                m[c] += 1;
            }
            else
            {
                m.insert({c, 1});
            }
        }
        
        for (int idx = 0; char& c : s)
        {
            if (m[c] == 1)
            {
                return idx;
            }
            ++idx;
        }
        return -1;
    }
};