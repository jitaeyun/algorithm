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
    ListNode* partition(ListNode* head, int x) {
        ListNode *ms=NULL, *me=NULL, *ls=NULL, *le=NULL;
        for(; head!=NULL; head=head->next){
            if(head->val<x){
                if(ms==NULL) ms=me=head;
                else {me->next=head; me=me->next;}
            }
            else {
                if(ls==NULL) ls=le=head;
                else {le->next=head; le=le->next;}
            }
        }
        if(ms) me->next=ls;
        else ms=ls;
        if(ls) le->next=NULL;
        return ms;
    }
};