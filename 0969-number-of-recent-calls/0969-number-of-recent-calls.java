class RecentCounter {
    public LinkedList<Integer> q;

    public RecentCounter() {
        q = new LinkedList<Integer>();
    }
    
    public int ping(int t) {
        this.q.addLast(Integer.valueOf(t));

        while (!q.isEmpty() && q.peekFirst() < Integer.valueOf(t - 3000)) {
            this.q.removeFirst();
        }
        return this.q.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */