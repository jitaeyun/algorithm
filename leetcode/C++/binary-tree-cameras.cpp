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
    int answer;
    void installCamera(TreeNode *parent, TreeNode *node){
        if(parent) ++parent->val;
        if(node->left) ++node->left->val;
        if(node->right) ++node->right->val;
        ++node->val;
        ++answer;
    }
    void checkCameras(TreeNode *parent, TreeNode *node){
        if(!node) return;
        checkCameras(node,node->left);
        checkCameras(node,node->right);
        if(node->left && node->left->val==0) installCamera(parent,node);
        else if(node->right && node->right->val==0) installCamera(parent,node);
    }
    int minCameraCover(TreeNode* root) {
        answer=0;
        checkCameras(NULL,root);
        return (root->val)? answer : answer+1;
    }
};