/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
#include <stdexcept>
class Solution {
public:
    int guessNumber(int n) 
    {
        int left = 1;
        int right = n;
        int mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            auto result = guess(mid);
            if (result == 0)
            {
                return mid;
            }
            else if (result == -1)
            {
                right = mid - 1;
            }
            else if (result == 1)
            {
                left = mid + 1;
                
            }
            else
            {
                throw std::runtime_error("invalid return value");
            }
            std::cout << "left = " << left << " right = " << right << std::endl;
        }
        return -1;
    }
};