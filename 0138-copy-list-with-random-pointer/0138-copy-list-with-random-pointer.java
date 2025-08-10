/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        HashMap<Node, Node> nodeMap = new HashMap<>();
        
        if (head == null) {
            return null;
        }
        
        Node oldItr = head;
        Node newItr = new Node(head.val);
        while(oldItr != null) {
            if (!nodeMap.containsKey(oldItr)) {
                nodeMap.put(oldItr, newItr);
            }

            if (oldItr.next != null) {
                if (nodeMap.containsKey(oldItr.next)) {
                    newItr.next = nodeMap.get(oldItr.next);
                } else {
                    newItr.next = new Node(oldItr.next.val);
                    nodeMap.put(oldItr.next, newItr.next);
                }
            }

            if (oldItr.random != null) {
                if (nodeMap.containsKey(oldItr.random)) {
                    newItr.random = nodeMap.get(oldItr.random);
                } else {
                    newItr.random = new Node(oldItr.random.val);
                    nodeMap.put(oldItr.random, newItr.random);
                }
            }
            
            oldItr = oldItr.next;
            newItr = newItr.next;
        }
        
        return nodeMap.get(head);
    }
}