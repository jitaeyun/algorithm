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
    ListNode* mergeList(ListNode* l, ListNode* r){
        if(l&&r){
            if(l->val>r->val){
                ListNode* t = l;
                l=r; r=t;
            }
            l->next = mergeList(l->next,r);
        }
        return (l)? l : r;
    }
    ListNode* sortList(ListNode* head) {
        ListNode *s=head,*f=head,*t=head;
        if(head==NULL || head->next==NULL) return head; 
        while(f->next && f->next->next){
            s=s->next;
            f=f->next->next;
        }
        t=s->next;
        s->next=NULL;
        ListNode *l = sortList(head);
        ListNode *r = sortList(t);
        return mergeList(l,r);
    }
};