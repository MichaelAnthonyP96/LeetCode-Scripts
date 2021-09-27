class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> wordGroups;
        unordered_map<string, int> m;
        for (auto& str : strs)
        {
            std::string sortedStr (str);
            std::sort (sortedStr.begin(), sortedStr.end());
            if (m.count(sortedStr) > 0)
            {
                wordGroups[m[sortedStr]].push_back(str);
            }
            else
            {
                std::vector<string> v {str};
                wordGroups.push_back(v);
                m.insert({sortedStr, wordGroups.size() - 1});
            }
        }
      
      return wordGroups;
    }
};