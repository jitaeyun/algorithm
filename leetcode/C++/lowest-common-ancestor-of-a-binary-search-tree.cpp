/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int mn=p->val,mx=q->val;
        if(p->val>q->val){mn=q->val; mx=p->val;}
        while(root->val < mn || root->val > mx){
            root = (root->val>mx)? root->left : root->right;
        }
        return root;
    }
};