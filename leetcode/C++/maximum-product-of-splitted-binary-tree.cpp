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
    int diff, allSum, a, b, t;
    const int MOD=1000000007;
    void traverseSum(TreeNode* node){
        TreeNode* n;
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty()){
            n=q.front(); q.pop();
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
            allSum+=n->val;
        }
    }
    int calcMax(TreeNode* root){
        if(root==nullptr) return 0;
        int left=calcMax(root->left);
        int right=calcMax(root->right);
        t = max(allSum-left,left)-min(allSum-left,left);
        if(diff>t) {diff=t; a=allSum-left; b=left;}
        t = max(allSum-right,right)-min(allSum-right,right);
        if(diff>t) {diff=t; a=allSum-right; b=right;}
        return left+right+root->val;
    }
    int maxProduct(TreeNode* root) {
        long long sol = 0;
        diff=MOD;
        allSum=a=b=0;
        traverseSum(root);
        calcMax(root);
        sol=(long long)(a)*(b)%MOD;
        return sol;
    }
};