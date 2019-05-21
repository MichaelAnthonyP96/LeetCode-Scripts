class Solution {
    public String longestCommonPrefix(String[] strs) {
        //set the minLength as the largest possible Integer number
        Integer minLength = Integer.MAX_VALUE;
        //find the length of the smallest string
        for(int i = 0; i < strs.length; i++){
            if(strs[i].length() < minLength){
                minLength = strs[i].length();
            }
        }
        //check to see if minLength is unchanged, this means one of two things:
        //the strs array is empty
        //on of the strs array elements in an empty string
        if(minLength == Integer.MAX_VALUE){
            return "";
        }
        //find common prefix
        int prefixCount = 0;
        search:
            //iterate over min number of letters
            for(int j = 0; j < minLength; j++){
                //iterate over all of the words
                for(int k = 0; k < strs.length; k++){
                    //if the letters don't match, break out of both loops
                    if(strs[0].charAt(j) != strs[k].charAt(j)){
                        break search;
                    }
                }
                //only increment prefixCount after all words have been checked
                prefixCount = j+1;
            }
        if(prefixCount != 0){
            return strs[0].substring(0,prefixCount);
        }
        else{
            return "";
        }
    }
}