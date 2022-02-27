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
    int widthOfBinaryTree(TreeNode* root) {
        TreeNode* cur = nullptr;
        long long sol = 0, val=0, diff=0, sz=0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            sz = q.size(); diff = q.front().second;
            for(int i=0; i<sz; ++i){
                cur = q.front().first; val=q.front().second; q.pop();
                if(cur->left) q.push({cur->left, (val-diff)*2});
                if(cur->right) q.push({cur->right, (val-diff)*2+1});
            }
            sol=max(sol, val-diff+1);
        }
        return sol;
    }
};