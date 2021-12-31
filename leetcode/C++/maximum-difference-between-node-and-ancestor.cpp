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
    int traverse(TreeNode* node, int mn, int mx){
        if(node == nullptr) return mx-mn;
        mn = min(mn, node->val);
        mx = max(mx, node->val);
        return max(traverse(node->left, mn, mx), traverse(node->right, mn, mx));
    }
    int maxAncestorDiff(TreeNode* root) {
        return traverse(root, root->val, root->val);
    }
};

/*
// another solution
class VALUES {
public:
    TreeNode* node;
    int mn;
    int mx;
};

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int sol = 0, mn=0, mx=0;
        TreeNode* cur = nullptr;
        stack<VALUES> st;
        st.push({root, root->val, root->val});
        while(!st.empty()){
            cur = st.top().node; mn = min(st.top().mn, cur->val); mx = max(st.top().mx, cur->val); st.pop();
            sol = max(sol, mx-mn);
            if(cur->left) st.push({cur->left, mn, mx});
            if(cur->right) st.push({cur->right, mn, mx});
        }
        return sol;
    }
};
*/