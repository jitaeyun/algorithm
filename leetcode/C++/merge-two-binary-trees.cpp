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
    void dfs(TreeNode* r, TreeNode* t){
        if(!r || !t) return;
        r->val+=t->val;
        if(r->left && t->left) dfs(r->left,t->left);
        else if(t->left) r->left=t->left;
        
        if(r->right && t->right) dfs(r->right,t->right);
        else if(t->right) r->right=t->right;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        dfs(root1,root2);
        return (!root1)? root2 : root1;
    }
};