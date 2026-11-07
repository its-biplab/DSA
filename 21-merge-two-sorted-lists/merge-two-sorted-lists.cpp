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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
/*      if(list1 == nullptr || list2 == nullptr){
        return list1 ==nullptr? list2:list1;
      }
      //case1 head1<head2
      if(list1->val <= list2->val){
           list1->next = mergeTwoLists(list1->next,list2);
             return list1;
      }
      //case2 head1>head2

       else{
            list2->next = mergeTwoLists(list1,list2->next);
             return list2;
      }
*/
        if(list1 == nullptr || list2 == nullptr){
        return list1 ==nullptr? list2:list1;
      }
    ListNode* t1 = list1;
    ListNode* t2 = list2;
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    while(t1 != NULL && t2 != NULL){
    if(t1->val <= t2->val){
        temp->next = t1;
        t1 = t1->next;
        temp = temp->next;
        }else{
            temp->next = t2;
            t2 = t2->next;
            temp = temp->next;
        }
    }
    if(t1 == NULL){
        temp->next = t2;
        return dummy->next;
    }else if(t2 == NULL){
        temp->next = t1;
        return dummy->next;
    }
    return dummy->next;
    }
};