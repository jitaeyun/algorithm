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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int sz=0;
        vector<vector<int>> sol;
        queue<TreeNode*> q;
        TreeNode* cur;
        if(!root) return sol;
        q.push(root);
        while(!q.empty()){
            sz=q.size();
            vector<int> v;
            for(int i=0; i<sz; ++i){
                cur=q.front(); q.pop();
                v.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            sol.push_back(v);
        }
        return sol;
    }
};