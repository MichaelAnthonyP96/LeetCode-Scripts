class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        std::unordered_set<int> s;
        std::unordered_set<int>::iterator itr, e = s.end();
        for (auto& num : nums)
        {
            itr = s.find(num);
            if (itr != e)
                s.erase(itr);
            else
                s.insert(num); 
        }
    return *(s.begin());
    }
};