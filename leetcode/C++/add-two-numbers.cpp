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
        ListNode* head=l1, *p;
        int c=0;
        for(; l1&&l2; l1=l1->next,l2=l2->next){
            l1->val+=l2->val+c;
            c=l1->val/10;
            l1->val%=10;
            p=l1;
        }
        if(l2) {
            p->next=l2;
            l1=l2;
        }
        for(; l1; l1=l1->next){
            if(c==0) break;
            l1->val+=c;
            c=l1->val/10;
            l1->val%=10;
            p=l1;
        }
        if(c) p->next = new ListNode(c);
        return head;
    }
};