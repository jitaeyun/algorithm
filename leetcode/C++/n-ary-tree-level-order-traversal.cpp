/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> sol;
        Node *node;
        int sz=0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            sz=q.size();
            vector<int> v;
            for(int i=0; i<sz; ++i){
                node=q.front(); q.pop();
                if(node==nullptr) continue;
                v.push_back(node->val);
                for(Node* t : node->children) q.push(t);
            }
            if(!v.empty()) sol.push_back(v);
        }
        return sol;
    }
};