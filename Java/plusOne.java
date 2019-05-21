/*Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.
*/
class Solution {
    public int[] plusOne(int[] digits) {
        //find the last digit
        int lastDigit = digits.length - 1;
        //check to see if the last digit is not a 9, if so increment and return
        if(digits[lastDigit] != 9){
            digits[lastDigit] += 1;
            return digits;
        } 
        //we now know the last digit is a 9
        //increment the digits moving right to left until a non-9 
        //or the last digit is encountered
        while( (lastDigit >= 0) && (digits[lastDigit] == 9) ){
            digits[lastDigit] = 0;
            lastDigit--;
        }
        //if all the digits were 9's, then create a new array with one extra digit
        //make the leading digit one and copy all others into the newDigits
        if(lastDigit == -1){
            int[] newDigits = new int[digits.length+1];
            newDigits[0] = 1;
            for(int i = 0; i < digits.length; i++ ){
                newDigits[i+1] = digits[i];
            }
            return newDigits;
        }
        //if only some of the digits were 9's, then increment the last non-9 and 
        //return digits
        else{
            digits[lastDigit] += 1;
        }
        return digits;
    }
}