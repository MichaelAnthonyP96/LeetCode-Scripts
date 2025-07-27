class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();

        for (int idx = 0; idx < numRows; ++idx) {
            ArrayList<Integer> row = new ArrayList<>(idx+1);
            row.add(0, 1);

            for (int j = 1; j < idx; ++j) {
                row.add(j, result.get(idx-1).get(j-1) + result.get(idx-1).get(j));
            }

            if (idx > 0) {
                row.add(idx, 1);
            }

            result.add(idx, row);
        }
        
        return result;
    }
}