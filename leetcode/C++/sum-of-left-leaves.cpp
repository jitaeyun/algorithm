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
    int sumOfLeftLeaves(TreeNode* root) {
        int sol=0;
        TreeNode* cur = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            cur=q.front(); q.pop();
            if(cur==nullptr) continue;
            if(cur->left) {
                q.push(cur->left);
                if(cur->left->left == nullptr && cur->left->right == nullptr) sol+=cur->left->val;
            }
            if(cur->right) q.push(cur->right);
        }
        return sol;
    }
};