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
    unordered_map<long,int> um[2];
    unordered_map<long,int>::iterator it;
    int traverse(TreeNode* node, int visit, long num){
        if(node==nullptr) return 0;
        if((it=um[visit].find(num))!=um[visit].end()) return it->second;
        if(visit) return node->val + traverse(node->left, 0, 2*num) + traverse(node->right, 0, 2*num+1);
        int a=traverse(node->left,1,2*num), b=traverse(node->left,0,2*num);
        int c=traverse(node->right,1,2*num+1), d=traverse(node->right,0,2*num+1);
        return um[visit][num]=max(a,b)+max(c,d);
    }
    int rob(TreeNode* root) {
        return max(traverse(root,1, 1), traverse(root,0,1));
    }
};