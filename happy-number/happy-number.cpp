#include <cmath>
class Solution {
public:
    bool isHappy(int n) {
      std::unordered_set<int> s;
      std::unordered_set<int>::iterator it = s.end();
      int result = n;
      while (result != 1) 
      {
        result = sumDigitSquares(result);
        if (s.find(result) != s.end()) 
        {
            return false;
        }
        s.insert(result);
      }
      return true;
    }
    
    int sumDigitSquares(int n) {
      int sum = 0;
      while (n != 0) {
        sum += std::pow((n % 10), 2);
        n /= 10;
      }
      return sum;
    }
};