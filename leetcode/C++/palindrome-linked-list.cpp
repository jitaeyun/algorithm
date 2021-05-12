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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode *f=head, *s=head, *r=nullptr, *t;
        while(f && f->next){
            f=f->next->next;
            t=s->next;
            if(r){
                s->next=r;
                r=s;
            }
            else{
                r=s;
                r->next=nullptr;
            }
            s=t;
        }
        if(f) s=s->next;
        for(; s!=nullptr&&r!=nullptr; s=s->next, r=r->next){
            if(r->val!=s->val) return false;
        }
        return true;
    }
};