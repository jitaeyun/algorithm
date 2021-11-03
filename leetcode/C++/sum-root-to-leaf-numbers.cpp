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
    int sumNumbers(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.emplace(root,0);
        TreeNode* node=nullptr;
        int cur=0, sol=0;
        while(!q.empty()){
            node=q.front().first; cur=q.front().second; q.pop();
            cur=cur*10+node->val;
            if(node->left) q.emplace(node->left, cur);
            if(node->right) q.emplace(node->right, cur);
            if(node->left == nullptr && node->right == nullptr) sol+=cur;
        }
        return sol;
    }
};