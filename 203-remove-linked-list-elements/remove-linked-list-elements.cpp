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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return NULL;
        }
       else if(head-> next == NULL){
            if(head->val == val) return NULL;
            else return head;
        }
        while(head != NULL && head->val == val){
            ListNode* temp = head;
            head = head->next;
            temp -> next = NULL;
            delete temp;
        }
        ListNode* temp = head;
        ListNode*prev = NULL;
        while(temp != NULL){
            
            if(temp->val == val){
                prev->next = temp->next;
                ListNode* del = temp;
                temp = temp->next;
                del->next = NULL;
                delete del;
                
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};