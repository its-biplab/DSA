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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        // ListNode* temp = head->next;
        // head -> next = swapPairs(head->next->next);
        // temp->next = head;
        // return temp;
        ListNode* temp = head;
        ListNode* front = head->next;
        ListNode* prev = NULL;
        head = front;
        while(temp != NULL && front != NULL){
            temp->next = front->next;
            front->next = temp;
            if(prev != NULL){
                prev->next = front;
            }
            prev = temp;
            temp = temp->next;
            if(temp == NULL) break;
            front = temp->next;
        }
        return head;
    }
};