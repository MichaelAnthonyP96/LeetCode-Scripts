class Solution {
    public String countAndSay(int n) {
        //check for appropriate bounds
        if(n<1 || n>30) return "error";
        //base case for recursion
        if(n == 1) return "1";
        //recursive case, adds 0 to end of each recursion layer to delimit
        //the end of the string
        String str = countAndSay(n-1) + "0";
        //initialize a Stringbuilder
        StringBuilder val = new StringBuilder();
        //counter variable for each unique 1, 2, or 3
        int c = 1;
        //iterate from the start of the string to the second to last term,
        //since we compare each term and the next adjacent one in the string
        for(int i = 0; i < str.length() - 1; i++, c++){
            //if the two terms are unequal, append the count prior to term 
            //itself and reset the counter to 0, which becomes 1 when this
            //iteration of the loop terminates
            if(str.charAt(i) != str.charAt(i+1)){
                val.append(c).append(str.charAt(i));
                c = 0;
            }
        }
        return val.toString();
    }
}