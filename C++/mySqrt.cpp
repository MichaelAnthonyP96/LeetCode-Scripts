class Solution {
public:
    int mySqrt(int x) {
        /*Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
         *Since the return type is an integer, the decimal digits are truncated and only the integer part
         *of the result is returned.
         */
        if( x <= 0) return 0; //base case of negatives and zero
        if( x == 1 ) return 1; //base case of 1
        unsigned int retVal = 1; //sqrt must be atleast 1
        while(true){
            //Since we are approaching from 1, if the current int and the next incremental int are 
            //respectively less than or equal to and greater than the input x, we have found the truncated
            //sqrt integer value of x
            if( (retVal * retVal <= x) && ( (retVal+1) * (retVal+1) > x) ){
                return retVal;
            }
            else{
                retVal++;
            }
        }
        
    }
};