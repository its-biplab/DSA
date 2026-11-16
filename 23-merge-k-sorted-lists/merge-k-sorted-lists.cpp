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
    ListNode* mergeTwoHead(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                res -> next = list1;
                res = list1;
                list1 = list1 ->next;
            }else{
               res -> next = list2;
                res = list2;
                list2 = list2 ->next; 
            }
            
        }
        if(list1) res->next = list1;
        else res->next = list2;
       
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        if(n == 0) return nullptr;
        if(n== 1) return lists[0];
        ListNode* mergeHead = lists[0];
        for(int i = 1; i<n; i++){
           mergeHead = mergeTwoHead(lists[i],mergeHead);
        }
        
        return mergeHead;
    }
};