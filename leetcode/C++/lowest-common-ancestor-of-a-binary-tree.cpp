/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> l,r;
    void findAncestor(TreeNode* node, int &val, vector<TreeNode*> &v){
        if(node==NULL) return;
        v.push_back(node);
        if(node->val==val) return;
        findAncestor(node->left,val,v);
        if(v.back()->val == val) return;
        findAncestor(node->right,val,v);
        if(v.back()->val == val) return;
        v.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findAncestor(root,p->val,l);
        findAncestor(root,q->val,r);
        while(l.size()<r.size()) r.pop_back();
        while(l.size()>r.size()) l.pop_back();
        while(l.back()->val!=r.back()->val) {
            l.pop_back();
            r.pop_back();
        }
        return l.back();
    }
};


//another solution
/*
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return root;
        if(root->val==p->val || root->val==q->val) return root;
        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);
        if(l==NULL) return r;
        else if(r==NULL) return l;
        return root;
    }
};
*/