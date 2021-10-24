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
    int getHeight(TreeNode* node){
        int l=-1;
        for(; node!=nullptr; node=node->left, ++l) {}
        return l;
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int sol=0,h=0;
        for(h=getHeight(root), sol=(1<<h); h>0; --h){
            if(getHeight(root->right)+1==h){
                root=root->right;
                sol+=(1<<(h-1));
            }
            else root=root->left;
        }
        return sol;
    }
};

/*
생각보다 o(N) 보다 작은 풀이가 떠오르지가 않음
*/