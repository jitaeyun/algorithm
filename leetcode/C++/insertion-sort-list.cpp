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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *sol=new ListNode(-5001), *t, *p;
        for(ListNode *cur=head; cur;){
            for(t=sol; t; p=t, t=t->next){
                if(t->val>cur->val) break;
            }
            p->next=cur;
            cur=cur->next;
            p->next->next=t;
        }
        return sol->next;
    }
};