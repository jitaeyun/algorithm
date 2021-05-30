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
    int minDiffInBST(TreeNode* root) {
        TreeNode *t;
        int sol=100001;
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            t=q.front(); q.pop(); v.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        sort(v.begin(),v.end());
        for(int i=0; i<v.size()-1; ++i) sol=min(sol,v[i+1]-v[i]);
        return sol;
    }
};