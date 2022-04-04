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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *l=nullptr, *r=nullptr;
        int t = 0, l_idx=--k, r_idx=0, idx=0;
        for(ListNode* cur=head; cur; cur=cur->next){
            if(idx==l_idx) l=cur;
            ++idx;
        }
        r_idx = idx-k-1; idx=0;
        for(ListNode* cur=head; cur; cur=cur->next){
            if(idx==r_idx) r=cur;
            ++idx;
        }
        t = l->val; l->val = r->val;
        r->val = t;
        return head;
    }
};