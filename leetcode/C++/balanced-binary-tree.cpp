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
    int dfs(TreeNode *n){
        if(!n) return 0;
        int a=dfs(n->left)+1;
        int b=dfs(n->right)+1;
        sol = (a>b)? max(sol,a-b) : max(sol,b-a);
        return max(a,b);
    }
    bool isBalanced(TreeNode* root) {
        sol=0;
        dfs(root);
        return sol<2;
    }
};