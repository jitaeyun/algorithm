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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *sol=new ListNode(),*cur=sol;
        priority_queue<pair<int, ListNode*>> pq;
        for(ListNode *n : lists) if(n) pq.push({-n->val,n});
        while(!pq.empty()){
            cur->next=pq.top().second; pq.pop();
            cur=cur->next;
            if(cur->next) pq.push({-cur->next->val,cur->next});
        }
        return sol->next;
    }
};