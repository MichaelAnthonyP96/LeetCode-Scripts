class Solution {
    public int lengthOfLastWord(String s) {
        //check base case
        if( s.length() == 0 ) return 0;
        //initialize wordCount variable
        int wordCount = 0;
        //initialize idx to the last viable index
        int idx = s.length() - 1;
        //move backwards in the string disregarding all spaces
        while( (idx >= 0) && (s.charAt(idx) == ' ') ){
            idx--;
        }
        //continue moving backwards in the string counting all non-spaces
        while( (idx >= 0) && (s.charAt(idx) != ' ')){
            wordCount++;
            idx--;
        }
        return wordCount;
    }
}