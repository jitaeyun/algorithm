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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    TreeNode* traverse(int l, int r){
        if(l>r) return nullptr;
        int m = l+(r-l)/2;
        return new TreeNode(v[m],traverse(l,m-1),traverse(m+1,r));
    }
    TreeNode* sortedListToBST(ListNode* head) {
        for(ListNode* cur=head; cur!=nullptr; cur=cur->next) v.push_back(cur->val);
        if(v.empty()) return nullptr;
        return traverse(0,v.size()-1);
    }
};