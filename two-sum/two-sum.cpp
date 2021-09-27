class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        std::unordered_map<int, int> m;
        std::vector<int> indices;
        for (int idx = 0; auto& num : nums)
        {
            if (m.count(target-num) > 0)
            {
                // we found a matching number which fits the criteria
                indices.push_back(m[target-num]);
                indices.push_back(idx);
                return indices;
            }
            else
            {
                m.insert({num, idx++});
            }
        }
        return indices;
    }
};