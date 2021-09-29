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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> sol;
        int lens=0,n=0,g=0;
        for(ListNode* cur=head; cur!=nullptr; cur=cur->next) ++lens;
        for(ListNode* cur=head, *t=nullptr; cur!=nullptr;){
            if(n==0) {
                n=(lens/k)+(lens%k>0);
                sol.push_back(cur);
            }
            if(--n==0) {
                t=cur->next;
                cur->next=nullptr;
                cur=t;
                if(lens%k) --lens;
                ++g;
            }
            else cur=cur->next;
        }
        for(; g<k; ++g) sol.push_back(nullptr);
        return sol;
    }
};