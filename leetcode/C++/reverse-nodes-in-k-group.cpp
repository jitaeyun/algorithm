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
    ListNode* reverse(ListNode* root, int &k){
        ListNode *cur=root->next, *prev=root->next;
        for(int i=0; i<k; ++i){
            if(i==0) cur=cur->next;
            else {
                prev->next = cur->next;
                cur->next = root->next;
                root->next = cur;
                cur=prev->next;
            }
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int sz=0;
        if(k<=1) return head;
        ListNode *root= new ListNode(0, head), *cur=root;
        //1. size를 알아냄
        for(ListNode *c=head; c!=NULL; c=c->next) ++sz;
        //2. group 별로 뒤집음
        for(int i=0; i<sz/k; ++i) cur=reverse(cur,k);
        //3. root 리턴
        return root->next;
    }
};