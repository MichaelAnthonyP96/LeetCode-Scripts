class Solution {
    public int secondHighest(String s) {
        PriorityQueue<Integer> reversedQueue = new PriorityQueue<>(Collections.reverseOrder());
        Set<Integer> knownValues = new HashSet<>();
        
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                int intValue = Character.getNumericValue(c);
                if (!knownValues.contains(intValue)) {
                    knownValues.add(intValue);
                    reversedQueue.add(intValue);
                }
            }
        }

        if (reversedQueue.size() < 2) {
            return -1;
        } else {
            reversedQueue.poll();
            return reversedQueue.peek();
        }
    }
}