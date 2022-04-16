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
    void traverse(TreeNode* node, int &sum){
        if(node==nullptr) return;
        traverse(node->right, sum);
        node->val+=sum;
        sum=node->val;
        traverse(node->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        traverse(root, sum);
        return root;
    }
};