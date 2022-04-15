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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode *cur=nullptr, *p=nullptr;
        TreeNode *sol = new TreeNode(-1);
        sol->right = root;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,sol});
        while(!q.empty()){
            cur=q.front().first; p=q.front().second; q.pop();
            if(cur==nullptr) continue;
            else if(cur->val<low) {
                if(p->left==cur){p->left=cur->right;}
                else {p->right=cur->right;}
                q.push({cur->right, p});
            }
            else if(cur->val>high){
                if(p->left==cur) {p->left=cur->left;}
                else {p->right=cur->left;}
                q.push({cur->left, p});
            }
            else{
                q.push({cur->left, cur});
                q.push({cur->right, cur});
            }
        }
        return sol->right;
    }
};