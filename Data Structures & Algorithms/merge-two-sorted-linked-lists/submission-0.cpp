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
        ListNode* dummy = new ListNode(-1); // dummy node
        ListNode* tail = dummy;


        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        while(curr1 && curr2){
            if(curr1->val < curr2->val){
                tail->next = curr1;
                curr1 = curr1->next;
            }else{
                tail->next = curr2;
                curr2 = curr2->next;
            }
            tail = tail->next;
        }

        if(curr1 != NULL) tail->next = curr1;
        if(curr2 != NULL) tail->next = curr2;

        return dummy->next;
    }
};
