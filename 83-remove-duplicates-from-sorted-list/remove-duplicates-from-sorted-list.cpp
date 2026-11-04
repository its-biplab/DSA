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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* back = head;
        ListNode* front = head->next;
        while(front != NULL){
            if(back->val == front->val){
                back->next = front ->next;
                ListNode*del  = front;
                front = front->next;
                del->next = NULL;
                delete del;
            }else{
                front = front->next;
                back= back->next;
            }
        }
        return head;
    }
};