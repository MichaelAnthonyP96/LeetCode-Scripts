class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int pos = nums1.length - 1;
        --m;
        --n;
        for (int i = pos; i >= 0; --i) {
            if (m == -1) {
                // copy nums2 into the final array
                nums1[i] = nums2[n];
                --n;
            } else if (n == -1) {
                // copy nums1 into the final array
                nums1[i] = nums1[m];
                --m;
            } else if (nums1[m] >= nums2[n]) {
                nums1[i] = nums1[m];
                --m;
            } else {
                nums1[i] = nums2[n];
                --n;
            }
        }
    }
}