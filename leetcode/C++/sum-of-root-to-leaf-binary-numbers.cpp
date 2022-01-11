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
    int sumRootToLeaf(TreeNode* root) {
        TreeNode* node=nullptr;
        int val = 0, sol = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        while(!q.empty()){
            node = q.front().first; val = ((q.front().second)<<1) + node->val; q.pop();
            if(node->left == nullptr && node->right == nullptr) sol += val;
            if(node->left) q.push({node->left, val});
            if(node->right) q.push({node->right, val});
        }
        return sol;
    }
};