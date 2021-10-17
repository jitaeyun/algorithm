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
    int sol;
    int curSum;
    unordered_map<int,int> um;
    void traverse(TreeNode *node, int &targetSum){
        if(node==nullptr) return;
        curSum+=node->val;
        if(curSum==targetSum) ++sol;
        sol+=um[curSum-targetSum];
        ++um[curSum];
        traverse(node->left, targetSum);
        traverse(node->right, targetSum);
        --um[curSum];
        curSum-=node->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        sol=curSum=0;
        traverse(root,targetSum);
        return sol;
    }
};

/*
o(n^2) 풀이는 떠올리기 쉬웠으나 o(n)은 떠올리기 쉽지 않았음.
*/