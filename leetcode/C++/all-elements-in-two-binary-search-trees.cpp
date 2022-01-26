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
    void traverse(TreeNode* node, vector<int>& v){
        if(node == nullptr) return;
        traverse(node->left, v);
        v.push_back(node->val);
        traverse(node->right, v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> r1,r2,sol;
        int r1_idx=0, r2_idx=0;
        traverse(root1, r1); traverse(root2, r2);
        for(; r1_idx<r1.size() && r2_idx<r2.size();){
            if(r1[r1_idx]<r2[r2_idx]) sol.push_back(r1[r1_idx++]);
            else sol.push_back(r2[r2_idx++]);
        }
        for(; r1_idx<r1.size(); ++r1_idx) sol.push_back(r1[r1_idx]);
        for(; r2_idx<r2.size(); ++r2_idx) sol.push_back(r2[r2_idx]);
        return sol;
    }
};