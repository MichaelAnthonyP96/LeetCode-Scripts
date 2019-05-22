/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;//base case
        ListNode* current = head;//current pointer to iterate through the list
        while(current != NULL && current->next != NULL){
            //if the two values are the same, skip over the next Node and try again
            if(current->val == current->next->val){
                current->next = current->next->next;
                continue;
            }
            else{
                //only when the current->val and current->next->val are different do you continue down
                //the list
                current = current->next;
            }
        }
        //return the head to the removed duplicates list
        return head;
    }
};