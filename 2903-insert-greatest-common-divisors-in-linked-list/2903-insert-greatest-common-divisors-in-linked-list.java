/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode ans = head;

        while (head.next != null) {
            ListNode middleNode = new ListNode(greatestCommonDivisor(head.val, head.next.val));
            middleNode.next = head.next;
            head.next = middleNode;
            head = middleNode.next;
        }

        return ans;
    }

    int greatestCommonDivisor(int a, int b) {
        int min = Math.min(a, b);

        while (min > 1) {
            if (a % min == 0 &&
                b % min == 0) {
                    return min;
                }
                --min;
        }
        
        return 1;
    }
}