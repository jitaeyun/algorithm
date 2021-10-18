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
    int dx, dy, px, py;
    void traverse(TreeNode *node, int &x, int &y, int p, int d){
        if(node==nullptr) return;
        else if(node->val == x) {dx=d; px=p;}
        else if(node->val == y) {dy=d; py=p;}
        traverse(node->left, x, y, node->val, d+1);
        traverse(node->right, x, y, node->val, d+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dx=dy=px=py=-1;
        traverse(root, x, y, -1, 0);
        if(dx==dy && px!=py) return true;
        return false;
    }
};