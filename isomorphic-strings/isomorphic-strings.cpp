class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        std::unordered_map<char, char> ms;
        std::unordered_map<char, char> mt;
        // we know that s and t are the same length;
        for (int i = 0; i < s.size(); ++i)
        {
            // we map char's in s to the equivalent in t
            // the char in s already has an entry in the map
            if (ms.count(s[i]) <= 0 && mt.count(t[i]) <= 0)
            {
                // insert into the mapping
                ms.insert({s[i], t[i]});
                mt.insert({t[i], s[i]});
            } 
            else if (!(ms[s[i]] == t[i] && mt[t[i]] == s[i]))
            {
                return false;
            }
        }
        
        return true;
    }
};