class Solution {
    public int removeDuplicates(int[] nums) {
        //check the base case of an empty array
        if(nums == null) return 0;
        //initialize the return counter
        int retCount = 0;
        //create a new hashMap
        Map<Integer, Boolean> map = new HashMap<Integer, Boolean>();
        //iterate over all values in nums
        for(int i = 0; i < nums.length; i++){
            //if the dictionary contains the value already as a key, skip over it
            if( map.containsKey( nums[i] ) ){
                continue;
            }
            //if not, add it to the dictionary, add it to the correct retCount index
            //and increment retCount
            else{
                nums[retCount++] = nums[i];
                map.put(nums[i], true);
            }
        }
    return retCount;
    }
}