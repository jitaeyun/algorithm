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
    vector<int> v;
    int sz;
    Solution(ListNode* head) {
        srand((unsigned int)time(NULL));
        for(ListNode* cur=head; cur; cur=cur->next)
            v.push_back(cur->val);
        sz = v.size();
    }
    
    int getRandom() {
        return v[rand()%sz];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */