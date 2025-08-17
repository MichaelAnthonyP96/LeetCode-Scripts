class Solution {
    
    public class Row implements Comparable<Row> {
        public int soldiers;
        public int idx;
        
        public Row(int soldiers, int idx) {
            this.soldiers = soldiers;
            this.idx = idx;
        }
        
        @Override
        public int compareTo(Row other) {
            if (this.soldiers < other.soldiers) {
                return -1;
            } else if (this.soldiers > other.soldiers) {
                return 1;
            } else {
                if (this.idx < other.idx) {
                    return -1;
                } else if (this.idx > other.idx) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }
    
    public int[] kWeakestRows(int[][] mat, int k) {
        int[] answer = new int[k];
        PriorityQueue<Row> pq = new PriorityQueue<>();
        
        // iterate over the rows and add them to the pw
        for(int i = 0; i < mat.length; ++i){
            int count = 0;
            for (int j = 0; j < mat[0].length; ++j) {
                if (mat[i][j] == 1) {
                    ++count;
                }
            }
            pq.add(new Row(count, i));
        }
        
        for (int a = 0; a < k; ++a) {
            answer[a] = pq.poll().idx;
        }
        
        return answer;
    }
}