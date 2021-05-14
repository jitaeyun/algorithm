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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd=NULL, *even=NULL, *cur=head, *es=NULL;
        for(int i=0; cur; cur=cur->next,++i){
            if(i%2==0) {
                if(!odd) odd=cur;
                else {
                    odd->next=cur;
                    odd=odd->next;
                }
            }
            else {
                if(!even) es=even=cur;
                else{
                    even->next=cur;
                    even=even->next;
                }
            }
        }
        if(odd) odd->next=es;
        if(even) even->next=NULL;
        return head;
    }
};