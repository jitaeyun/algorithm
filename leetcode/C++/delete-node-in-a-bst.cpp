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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *sol=root, *d_node=nullptr, *p_node=nullptr, *s_node=nullptr, *sp_node=nullptr;
        for(TreeNode* cur=root; cur; ){
            if(cur->val==key){d_node=cur; break;}
            else if(cur->val<key) {p_node=cur; cur=cur->right;}
            else {p_node=cur; cur=cur->left;}
        }
        if(d_node==nullptr) return root;
        else if(d_node->right && d_node->left){
            s_node=d_node->right; sp_node=d_node->right;
            while(s_node->left){
                sp_node=s_node;
                s_node=s_node->left;
            }
            if(s_node!=sp_node) sp_node->left=s_node->right;
            else d_node->right = s_node->right;
            s_node->left=d_node->left;
            s_node->right=d_node->right;
        }
        else if(d_node->left) s_node = d_node->left;
        else if(d_node->right) s_node = d_node->right;
        if(p_node==nullptr) sol = s_node;
        else if(p_node->left==d_node) p_node->left = s_node;
        else p_node->right = s_node;
        return sol;
    }
};