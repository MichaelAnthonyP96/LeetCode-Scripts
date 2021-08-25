#include <algorithm>

class Solution {
public:
    
    
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        verticalCuts.insert(verticalCuts.begin(), 0);
        verticalCuts.insert(verticalCuts.end(), w);
        horizontalCuts.insert(horizontalCuts.begin(), 0);
        horizontalCuts.insert(horizontalCuts.end(), h);
        std::sort(horizontalCuts.begin(), horizontalCuts.end());
        std::sort(verticalCuts.begin(), verticalCuts.end());
        
        std::size_t hMax = 0, wMax = 0;
        for (int i = 1; i < horizontalCuts.size(); ++i)
        {
            std::size_t potentialMax = horizontalCuts[i] - horizontalCuts[i-1];
            if (potentialMax > hMax)
            {
                hMax = potentialMax;
            }
        }
        for (int i = 1; i < verticalCuts.size(); ++i)
        {
            std::size_t potentialMax = verticalCuts[i] - verticalCuts[i-1];
            if (potentialMax > wMax)
            {
                wMax = potentialMax;
            }
        }
        return (int)((hMax * wMax) % (long long )(1e9 + 7));
        
    }
};