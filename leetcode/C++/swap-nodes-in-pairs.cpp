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
    ListNode* t;
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *prev=head->next;
        t=head->next->next;
        prev->next=head;
        head->next=swapPairs(t);
        return prev;
    }
};