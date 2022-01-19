/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *c=head, *f=head;
        while((f && f->next)){
            c=c->next; f=f->next->next;
            if(c==f) break;
        }
        if(f == nullptr || f->next == nullptr) return nullptr;
        c=head;
        while(c!=f) {c=c->next; f=f->next;}
        return c;
    }
};