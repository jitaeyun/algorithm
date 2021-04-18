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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=0;
        ListNode* arr[30];
        for(ListNode* p = head; p; p=p->next) arr[sz++]=p;
        if(sz-n<1) head=head->next;
        else arr[sz-n-1]->next=arr[sz-n]->next;
        return head;
    }
};