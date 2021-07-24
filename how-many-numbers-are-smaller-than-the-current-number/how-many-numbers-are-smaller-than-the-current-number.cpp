class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        std::vector<int>returnValues(nums.size(), 0);
        
        for (int i = 0; i < n; ++i)
        {
            int count = 0;
            for (int j = 0; j < n; ++j)
            {
             
                if (i == j)
                {
                    // we do not want to consider the same element
                    continue;
                }
                if (nums[j] < nums[i])
                {
                    // increase the count for the element we are current considering
                    ++count;
                }
            }
            returnValues[i] = count;
        }
        return returnValues;
    }
};