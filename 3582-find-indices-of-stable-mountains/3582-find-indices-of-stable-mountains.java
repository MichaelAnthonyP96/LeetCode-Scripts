class Solution {
    public List<Integer> stableMountains(int[] height, int threshold) {

        ArrayList<Integer> mountains = new ArrayList<>();
        for (int i = 1; i < height.length; ++i) {
            if (height[i-1] > threshold) {
                mountains.add(i);
            }
        }
        
        return mountains;
    }
}