/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        ListNode* curr = head;
        for(int i = 0; i < left-1; i++){
        prev = prev->next;
        curr = curr->next;
        }
        
        for(int i=0; i < right-left; i++){
            ListNode* front = curr->next;
            curr->next = front->next;
            front ->next = prev ->next;
            prev->next= front;;
            
        }
        return dummy.next;
    }
};