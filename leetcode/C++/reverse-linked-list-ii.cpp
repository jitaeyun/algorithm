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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *s=NULL, *p=NULL, *cur=head;
        for(int i=0; i<left; ++i, cur=cur->next) {s=p; p=cur;}
        for(int i=left; i<right; ++i,cur=p->next){
            p->next=cur->next;
            if(s) {
                cur->next=s->next;
                s->next=cur;
            }
            else{
                cur->next=head;
                head=cur;
            }
        }
        return head;
    }
};