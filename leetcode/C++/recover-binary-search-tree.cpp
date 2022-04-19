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
    int idx;
    void traverse(TreeNode* node){
        if(node==nullptr) return;
        traverse(node->left);
        node->val=v[idx++];
        traverse(node->right);
    }
    void recoverTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *cur = nullptr;
        idx = 0;
        while(!q.empty()){
            cur=q.front(); q.pop();
            v.push_back(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        sort(v.begin(), v.end());
        traverse(root);
    }
};