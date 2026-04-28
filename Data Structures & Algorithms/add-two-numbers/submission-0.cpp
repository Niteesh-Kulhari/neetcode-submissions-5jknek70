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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;

        while(temp1 || temp2 || carry){
            int num1 = (temp1) ? temp1->val : 0;
            int num2 = (temp2) ? temp2->val : 0;
            int sum = num1 + num2 + carry;
            int rem = sum % 10;
            carry = sum / 10;
            head->next = new ListNode(rem);
            head = head->next;

            if (temp1) temp1 = temp1->next;
            if (temp2) temp2 = temp2->next;
        }

        return dummy->next;
    }
};
