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

class Compare{
public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        for(ListNode* list: lists){
            pq.push(list);
        }

        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            curr->next = temp;
            curr = curr->next;

            if(temp->next != NULL) pq.push(temp->next);
        }

        return dummy->next;

    }
};
