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
    TreeNode *t;
    void dfs(TreeNode *n){
        if(!n) return;
        t=n->left;
        n->left=n->right;
        n->right=t;
        dfs(n->left);
        dfs(n->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};


/*
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* cur = nullptr, *t = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            cur=q.front(); q.pop();
            if(cur==nullptr) break;
            t=cur->left; cur->left=cur->right; cur->right=t;
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return root;
    }
};
*/