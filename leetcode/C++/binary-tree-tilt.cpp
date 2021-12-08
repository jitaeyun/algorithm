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
    int traverse(TreeNode* node, int &sol){
        if(node==nullptr) return 0;
        int l=traverse(node->left, sol), r=traverse(node->right, sol);
        sol += (l>r)? l-r: r-l;
        return l+r+node->val;
    }
    int findTilt(TreeNode* root) {
        int sol = 0;
        traverse(root,sol);
        return sol;
    }
};