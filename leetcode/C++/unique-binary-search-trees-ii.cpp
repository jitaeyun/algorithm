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
    vector<int> visit;
    vector<TreeNode*> traverse(int l, int r){
        vector<TreeNode*> res;
        if(l>r) return {nullptr};
        for(int i=l; i<=r; ++i){
            if(visit[i]++) continue;
            for(TreeNode* j : traverse(l,i-1)){
                for(TreeNode* k : traverse(i+1,r)){
                    res.push_back(new TreeNode(i,j,k));
                }
            }
            visit[i]=0;
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        visit=vector<int>(n+1,0);
        return traverse(1,n);
    }
};