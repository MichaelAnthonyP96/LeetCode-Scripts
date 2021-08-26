#include <algorithm>
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int answer = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq (sticks.begin(), sticks.end());
        while (pq.size() > 1)
        {
            // pop the first smallest
            int first = pq.top();
            pq.pop();
            
            // pop the second smallest
            int second = pq.top();
            pq.pop();
            
            answer += (first + second);
            pq.emplace(first + second);
        }
        return answer;
    }
};