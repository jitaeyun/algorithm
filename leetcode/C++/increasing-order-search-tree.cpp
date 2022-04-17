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
    vector<TreeNode*> v;
    void traverse(TreeNode* node){
        if(node==nullptr) return;
        traverse(node->left);
        v.push_back(node);
        traverse(node->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        traverse(root);
        for(int i=0; i<v.size(); ++i){
            v[i]->left=v[i]->right=nullptr;
            if(i>0) v[i-1]->right=v[i];
        }
        return v[0];
    }
};