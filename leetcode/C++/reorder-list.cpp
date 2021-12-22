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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode *p=nullptr, *cur=nullptr;
        for(cur = head; cur; cur=cur->next) v.push_back(cur);
        cur=head;
        for(int i=0; i<v.size(); ++i){
            if(i&1) cur->next = v[v.size()-1-i/2];
            else cur->next = v[i/2];
            cur=cur->next; cur->next=nullptr;
        }
    }
};