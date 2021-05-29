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
    int sol;
    void traverse(TreeNode* node){
        if(!node) return;
        traverse(node->right);
        sol+=node->val;
        node->val=sol;
        traverse(node->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        sol=0;
        traverse(root);
        return root;
    }
};