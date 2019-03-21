/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
       //check the base case scenarios of when one or both of the lists are empty
       if(l1 == null && l2 == null) return null;
       if(l1 == null && l2 != null) return l2;
       if(l1 != null && l2 == null) return l1;
       //initialize pointers for the start and end of the new sorted list
       ListNode head = null; 
       ListNode tail = null;
       //assign the head to the smaller head of the two lists 
       //if theyre equal set it to l1 by default
        if(l1.val <= l2.val){
            head = l1;
            l1 = l1.next;
        }
        else{
            head = l2;
            l2 = l2.next;
        }
        //initialize the tail to the same value as the head before merging the two lists
        tail = head;
        /*only break out of the loop once one of the lists has been iterated through,
        this means that the remaining values in the other lists are all larger and
        sorted and can be added to the end of the returned array
        */
        while(true){
            if(l1 == null){
                tail.next = l2;
                break;
            }
            if(l2 == null){
                tail.next = l1;
                break;
            }
        /*add the smaller of the two current values to the end of the returned list,
        advance the pointer of the value which was added to the end of the returned list
        */
            if(l1.val <= l2.val){
                tail.next = l1;
                l1 = l1.next;
            }
            else{
                tail.next = l2;
                l2 = l2.next;
            }
            //make sure to advance the tail at the end of adding to the returned list 
            tail = tail.next;
        }
        //printList(head);
        return head;
    }
    
    public void printList(ListNode head){
        ListNode temp = head;
        while(temp != null){
            System.out.print(temp.val + "->");
            temp = temp.next;
        }
    }
}