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
    int dfs(TreeNode* node, int maxVal){
        int count=0;
        if(node==nullptr) return count;
        if(node->val>=maxVal) {
            ++count;
            maxVal=node->val;
        }
        count+=dfs(node->left,maxVal)+dfs(node->right,maxVal);
        return count;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,-100000);
    }
};