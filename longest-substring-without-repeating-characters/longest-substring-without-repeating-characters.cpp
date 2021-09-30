class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        std::unordered_map<char, int> m;
        int longestSubStr = 0;
        int tmpLongSubStr = 0;
        for (int i = 0; i < s.size(); )
        {
            char c = s[i];
            if (m.count(c) > 0)
            {
                // we've seen this char before, reset the set and 
                // potentially update the longestSubStr
                if (tmpLongSubStr > longestSubStr)
                {
                    longestSubStr = tmpLongSubStr;
                }
                tmpLongSubStr = 0;
                // reset the counter back to the position of the previous instance of this character + 1
                i = m[c] + 1;
                m.clear();
                
            }
            else
            {
                ++tmpLongSubStr;
                m.insert({c, i++});
            }
        }
        return std::max(tmpLongSubStr, longestSubStr);
    }
};