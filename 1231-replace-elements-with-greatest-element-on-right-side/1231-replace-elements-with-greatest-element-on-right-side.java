class Solution {
    public int[] replaceElements(int[] arr) {
        if (arr.length == 0) return arr;
        int currentMax = arr[arr.length-1];
        arr[arr.length-1] = -1;
        
        for (int i = arr.length - 2; i >= 0; --i) {
            int oldValue = arr[i];
            arr[i] = currentMax;
            if (oldValue > currentMax) {
                currentMax = oldValue; 
            }
        }
        return arr;
    }
}