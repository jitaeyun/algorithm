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
    int idx;
    void traverse(vector<int>& preorder, int upper, int lower, TreeNode *cur){
        if(idx==preorder.size()) return;
        if(preorder[idx]<upper && preorder[idx]>lower && preorder[idx]<cur->val){
            cur->left=new TreeNode(preorder[idx++]);
            traverse(preorder, cur->val, lower, cur->left);
        }
        if(idx<preorder.size() && preorder[idx]<upper && preorder[idx]>lower && preorder[idx]>cur->val){
            cur->right=new TreeNode(preorder[idx++]);
            traverse(preorder, upper, cur->val, cur->right);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode * sol = new TreeNode(preorder[idx++]);
        traverse(preorder, 10000, 0 , sol);
        return sol;
    }
};


/*
o(n) 솔루션 찾기 어려웠음.
*/