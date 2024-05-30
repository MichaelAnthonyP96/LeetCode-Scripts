/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int lower = 0;
        int upper = n;
        Long number = (upper + lower) / 2L;
        int result = guess(number.intValue());
        while (result != 0) {
            if (result == -1) {
                // guess is higher than the number
                // search the lower half
                upper = number.intValue() - 1;
            } else if (result == 1) {
                // guess is lower than the number
                // search the upper half
                lower = number.intValue() + 1;
            } else {
                // we found the number
                return number.intValue();
            }
            number = ((long)upper + lower) / 2L;
            result = guess(number.intValue());
        }
        return number.intValue();
    }
}