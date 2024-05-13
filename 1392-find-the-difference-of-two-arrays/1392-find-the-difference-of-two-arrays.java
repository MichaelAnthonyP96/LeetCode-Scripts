class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        List<Integer> list1 = getUniqueElementsInFirstList(nums2, nums1);
        List<Integer> list2 = getUniqueElementsInFirstList(nums1, nums2);
    

        List<List<Integer>> returnList = new ArrayList<>();
        returnList.add(list1);
        returnList.add(list2);
        return returnList;

    }

    public List<Integer> getUniqueElementsInFirstList(int[] nums1, int[] nums2) {
        List<Integer> uniqueVals = new ArrayList<>();
        Set<Integer> set = new HashSet<>();

        for (int num1 : nums1) {
            set.add(Integer.valueOf(num1));
        }

        // iterate over nums2
        for (int num2 : nums2) {
            Integer currentNum = Integer.valueOf(num2);
            if (!set.contains(currentNum)) {
                uniqueVals.add(currentNum);
                // add the value to the set, to prevent duplicates
                set.add(currentNum);
            }
        }

        return uniqueVals;
    }
}