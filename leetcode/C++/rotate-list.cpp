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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *sol = head, *tail=nullptr, *t=nullptr;
        int sz = 0, i=0;
        if(sol==nullptr) return sol;
        // 1. get node size and tail node
        for(ListNode *cur=head; cur; cur=cur->next) {++sz; tail=cur;}
        // 2. find rotate start idx, end idx
        int s_idx=(sz-(k%sz))%sz;
        int e_idx=(s_idx-1+sz)%sz;
        // 3. process s_idx, e_idx
        for(ListNode *cur=head; cur&&i<=max(s_idx,e_idx); cur=cur->next, ++i){
            if(i==s_idx) sol=cur;
            if(i==e_idx) t=cur;
        }
        tail->next=head;
        t->next=nullptr;
        return sol;
    }
};