class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        // count the number of values in num1
        std::unordered_map<int, int> m;
        std::vector<int> returnValues;
        for (auto& num : nums1)
        {
            if (m.count(num) > 0)
            {
                m[num] += 1;
            }
            else
            {
                m.insert({num, 1});
            }
        }
        
        // check to see if they are in nums2
        for (auto& num : nums2)
        {
            if (m[num] > 0)
            {
                returnValues.push_back(num);
                m[num] -= 1;
            }
        }
        return returnValues;
    }
};