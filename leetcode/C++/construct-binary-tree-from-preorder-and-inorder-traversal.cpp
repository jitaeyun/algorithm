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
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int &idx, int s, int e){
        if(idx == preorder.size()) return NULL;
        for(int i=s; i<=e; ++i){
            if(preorder[idx]!=inorder[i]) continue;
            TreeNode* t = new TreeNode(preorder[idx++]);
            t->left=dfs(preorder,inorder,idx,s,i-1);
            t->right=dfs(preorder,inorder,idx,i+1,e);
            return t;
        }
        return NULL;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        return dfs(preorder,inorder,idx,0,inorder.size()-1);
    }
};