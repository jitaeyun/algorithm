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
    ListNode* t;
public:
    ListNode* reverseList(ListNode* head, ListNode* p=NULL) {
        if(head==NULL) return head;
        t=head->next;
        head->next=p;
        return t? reverseList(t,head) : head;
    }
};