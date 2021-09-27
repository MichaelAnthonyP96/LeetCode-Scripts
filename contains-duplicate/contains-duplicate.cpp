class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        std::unordered_set<int> s;
        for (auto& itr : nums)
        {
            if (s.count(itr) > 0)
            {
                return true;
            }
            else
            {
                s.insert(itr);
            }
        }
        return false;
    }
};