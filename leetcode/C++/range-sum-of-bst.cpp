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
    int rangeSumBST(TreeNode* root, int low, int high) {
        TreeNode* t;
        int sol=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            t=q.front(); q.pop();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            if(t->val>=low && t->val<=high) sol+=t->val;
        }
        return sol;
    }
};