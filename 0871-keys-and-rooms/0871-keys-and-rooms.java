class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        if (rooms.isEmpty()) return true;
        Set<Integer> visitedRooms = new HashSet<>();
        Deque<List<Integer>> stack = new ArrayDeque<>();
        stack.offer(rooms.get(0));
        visitedRooms.add(0);
        // Use a stack to perform DFS, keeping track of the rooms we've
        // already visited
        while (!stack.isEmpty()) {
            List<Integer> curr = stack.pop();

            for (Integer i : curr) {
                // if the room has not already been visited, add it
                // to the list of visited and push the keys in that
                // room to the stack
                if (visitedRooms.add(i)) {
                    stack.push(rooms.get(i));
                }
            }
        }

        // if the size of visited rooms is equal to the number of rooms, 
        // then we can visit each room
        return visitedRooms.size() == rooms.size();
    }
}