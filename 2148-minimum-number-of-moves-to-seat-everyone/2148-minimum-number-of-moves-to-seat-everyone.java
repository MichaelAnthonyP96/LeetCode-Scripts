class Solution {
    public int minMovesToSeat(int[] seats, int[] students) {
        Arrays.sort(seats);
        Arrays.sort(students);
        int n = seats.length;
        int moves = 0;

        for (int idx = 0; idx < n; ++idx) {
            moves += Math.abs(seats[idx] - students[idx]);
        }

        return moves;
    }
}