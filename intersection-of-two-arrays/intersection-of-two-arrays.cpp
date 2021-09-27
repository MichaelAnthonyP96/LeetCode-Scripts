class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        std::unordered_set<int> s;
        // insert all elems in num1 into the hash set
        for (auto& itr : nums1)
        {
            if (s.count(itr) <= 0)
            {
                s.insert(itr);
            }
        }
        
        // iterate all elems in num2 and determine if they are already in the set,
        // if they are add them to the vector of returned values
        std::vector<int> intersectValues;
        for (auto& itr : nums2)
        {
            if (s.count(itr) > 0)
            {
                intersectValues.push_back(itr);
                s.erase(s.find(itr));
            }
        }
        return intersectValues;
    }
};