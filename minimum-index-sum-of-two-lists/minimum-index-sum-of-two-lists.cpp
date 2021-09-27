class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        std::unordered_map<string, int> m;
        // insert all values from list1 into the 
        for (int idx = 0; auto& itr : list1)
        {
            m.insert({itr, idx++});
        }
        
        std::vector<string> matchingValues;
        int lowestSum = INT_MAX;
        // iterate the second list and check to see if they are alreay in the list
        for (int idx = 0; auto& itr : list2)
        {
            if (m.count(itr) > 0)
            {
                int tmpSum = m[itr] + idx;
                if (tmpSum < lowestSum)
                {
                    lowestSum = tmpSum;
                    matchingValues.clear();
                    matchingValues.push_back(itr);
                }
                else if (tmpSum == lowestSum)
                {
                    matchingValues.push_back(itr);
                }
            }
            idx++;
        }
        return matchingValues;
    }
};