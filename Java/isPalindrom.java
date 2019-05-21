import java.util.ArrayList;
class Solution {
    public boolean isPalindrome(int x) {
        //negative numbers are never palindromes
        if(x < 0 ) return false;
        //initialize a new arrayList
        ArrayList<Integer> AList = new ArrayList<Integer>();
        //add all terms from x to the array list one by one to the end of the list
        while(x != 0){
            int pop = x % 10;
            AList.add(pop);
            x = x/10;
        }
        
        while( !AList.isEmpty() ){
            //compare the last value in the list to the first value in the list
            if(AList.get(0) != AList.get( AList.size() - 1 )) return false;
            else{
                AList.remove(AList.size() - 1);
                if(!AList.isEmpty()){
                    AList.remove(0);
                }
            }
        }
    return true;    
    }
}