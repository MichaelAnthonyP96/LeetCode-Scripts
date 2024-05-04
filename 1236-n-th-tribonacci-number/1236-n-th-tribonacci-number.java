class Solution {
    public int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        int[] tribValues = new int[n+1];
        
        // base cases
        tribValues[0] = 0;
        tribValues[1] = 1;
        tribValues[2] = 1;
        
        for (int i = 3; i < n+1; ++i) {
            tribValues[i] = tribValues[i-1] + tribValues[i-2] + tribValues[i-3];
        }
        return tribValues[n];
    }
}