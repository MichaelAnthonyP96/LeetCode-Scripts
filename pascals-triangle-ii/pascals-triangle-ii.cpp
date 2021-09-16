class Solution {
public:
    
    int pascalTri(int i, int j, std::map<std::pair<int, int>, int>& knownVals)
    {
        if (j == 0 || j == i)
        {
            return 1;
        }
        else
        {
            auto result1 = knownVals.find(std::make_pair(i-1, j-1));
            int one = 0;
            if (result1 != knownVals.end())
            {
                // we have computed this value before
                one = result1->second;
            }
            else
            {
                one = pascalTri(i-1, j-1, knownVals);
                knownVals.insert({{i-1, j-1}, one});
            }
            
            auto result2 = knownVals.find(std::make_pair(i-1, j));
            int two = 0;
            if (result2 != knownVals.end())
            {
                // we have computed this value before
                two = result2->second;
            }
            else
            {
                two = pascalTri(i-1, j, knownVals);
                knownVals.insert({{i-1, j}, two});
            }
            
            return one + two;
        }   
    }
    
    vector<int> getRow(int rowIndex) 
    {
        std::map<std::pair<int, int>, int> knownVals;
        std::vector<int> v;
        for (int i = 0; i < rowIndex + 1; ++i)
        {
            v.emplace_back(pascalTri(rowIndex, i, knownVals));
        }
        
        return v;
    }
};