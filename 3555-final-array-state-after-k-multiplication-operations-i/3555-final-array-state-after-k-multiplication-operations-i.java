import java.util.SortedMap;
import java.util.TreeMap;

class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {

        // build mapping of value to index
        SortedMap<Integer, ArrayList<Integer>> map = new TreeMap<>();
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            map.computeIfAbsent(nums[i], q -> new ArrayList<>()).add(i);
        }

        int lowestVal;
        ArrayList<Integer> idxList;
        int newVal;
        int idx;

        for (int j = 0; j < k; ++j) {
            lowestVal = map.firstKey();
            idxList = map.get(lowestVal);
            newVal = lowestVal * multiplier;
            Collections.sort(idxList);
            idx = idxList.get(0);
            idxList.remove(0);
            if (idxList.isEmpty()) {
                map.remove(lowestVal);
            }
            map.computeIfAbsent(newVal, q -> new ArrayList<>()).add(idx);
            nums[idx] = newVal;
        }

        return nums;
    }
}