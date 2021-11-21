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
    TreeNode* traverse(vector<int>& inorder, vector<int>& postorder, int il, int ir, int &p){
        TreeNode *node = nullptr;
        if(il>ir) return node;
        int im=il;
        for(; im<=ir; ++im) if(inorder[im]==postorder[p]) break;
        node = new TreeNode(postorder[p--]);
        node->right = traverse(inorder,postorder, im+1, ir, p);
        node->left = traverse(inorder,postorder, il, im-1, p);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int p=(int)postorder.size()-1;
        return traverse(inorder,postorder,0,inorder.size()-1,p);
    }
};