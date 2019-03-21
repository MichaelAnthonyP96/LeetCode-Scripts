import java.util.Arrays;
class Solution {
    public int removeElement(int[] nums, int val) {
        //initialize return count and counter of the number of values to be removed
        int retCount = 0;
        int offset = 0;
        //sort the array
        Arrays.sort(nums);
        //iterate over all sorted values in nums
        for(int i = 0; i < nums.length; i++){
            //if the current nums value does not equal val, increase the returnCount
            if( nums[i] != val){
                retCount++;
                //since the array is sorted, once you've pasted the values of val
                //you can shift the index of everything down by the number of offset
                if(offset != 0){
                    nums[i - offset] = nums[i];
                }
            }
            else{
                offset++;
            }
        }
        return retCount;
    }
}