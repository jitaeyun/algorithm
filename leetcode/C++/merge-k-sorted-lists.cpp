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
        priority_queue<pair<int, int>> pq;
        int idx = 0;
        for(int i=0; i<lists.size(); ++i) if(lists[i]) pq.push({-lists[i]->val,i});
        while(!pq.empty()){
            idx = pq.top().second; pq.pop();
            cur->next=lists[idx]; cur=cur->next;
            if(lists[idx]->next) {
                lists[idx]=lists[idx]->next;
                pq.push({-lists[idx]->val,idx});
            }
        }
        return sol->next;
    }
};