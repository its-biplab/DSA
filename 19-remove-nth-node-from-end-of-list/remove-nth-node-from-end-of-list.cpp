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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
/*        ListNode*temp = head;
        int count = 0;
        while(temp != nullptr){
           count++;
            temp = temp->next;
        }
        if (count == n){
            ListNode*newhead = head->next;
            delete head;
            return newhead;
        }
         temp = head;
        for(int i = 1; i < count -n; i++){
            temp = temp->next;
        }
        ListNode*toDel = temp->next;
        temp->next =temp->next->next;
        delete toDel;
        return head;    //T.C = 2N AND S.C = 1
*/

        ListNode*slow = head;
        ListNode*fast = head;
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        if (fast == NULL){
            ListNode*newhead = head->next;
            delete head;
            return newhead;
        }
        while(fast ->next != NULL){
            fast = fast-> next;
            slow = slow->next;
        }
        ListNode*del = slow->next;
        slow -> next = slow->next->next;
        del -> next = NULL;
        delete del;
        return head;
       }
    
};