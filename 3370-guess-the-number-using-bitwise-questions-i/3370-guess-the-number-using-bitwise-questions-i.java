/** 
 * Definition of commonSetBits API (defined in the parent class Problem).
 * int commonSetBits(int num);
 */

public class Solution extends Problem {
    public int findNumber() {
        int result = 0;

        for (int i = 1; i >= 0; i <<= 1) {
            if (commonSetBits(i) > 0) {
                result |= i;
            }
        }

        return result;  
    }
}