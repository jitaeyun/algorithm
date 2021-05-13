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
    ListNode* head;
    void traverse(ListNode* h, ListNode* l1, ListNode* l2){
        if(l1==NULL && l2==NULL) h->next=NULL;
        else if(l1==NULL) h->next=l2;
        else if(l2==NULL) h->next=l1;
        else {
            if(l1->val<l2->val){
                h->next=l1;
                traverse(h->next,l1->next,l2);
            }
            else {
                h->next=l2;
                traverse(h->next,l1,l2->next);
            }
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        head=new ListNode();
        traverse(head,l1,l2);
        return head->next;
    }
};