class Solution {
    public boolean validMountainArray(int[] arr) {
        int n = arr.length;
        // edge case, we cannot have a mountain if the array contains
        // less than three elements
        if (n < 3) {
            return false;
        } else if (arr[0] > arr[1]) {
            // we are decreasing from the start, which is not a mountain
            return false;
        }
        
        boolean decreasing = false;
        for (int i = 0; i < (arr.length-1); ++i) {
            if (arr[i+1] == arr[i]) {
                return false;
            } else if (decreasing && (arr[i+1] > arr[i])) {
                return false;
            } else if (arr[i+1] < arr[i]) {
                decreasing = true;
            }
        }
        // if we never decrease down the mountain, then it isn't a mountain
        // this flag should be set to true by the end of the array
        return decreasing;
    }
}