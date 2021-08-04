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
    vector<vector<int>> sol;
    vector<int> st;
    void dfs(TreeNode* node, int curSum, int &targetSum){
        if(node==nullptr) return;
        curSum+=node->val;
        st.push_back(node->val);
        if(node->left == nullptr && node->right == nullptr && curSum==targetSum) sol.push_back(st);
        dfs(node->left, curSum, targetSum);
        dfs(node->right, curSum, targetSum);
        st.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, 0, targetSum);
        return sol;
    }
};