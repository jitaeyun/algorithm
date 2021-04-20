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
//1. DFS
class Solution {
public:
    vector<int> sol;
    void dfs(Node* node){
        if(node==NULL) return;
        sol.push_back(node->val);
        for(int i=0; i<node->children.size()&&node->children[i]; ++i) {
            dfs(node->children[i]);
        }
    }
    vector<int> preorder(Node* root) {
        dfs(root);
        return sol;
    }
};
/*
//2. Stack
class Solution {
public:
    vector<int> sol;
    stack<Node*> st;
    vector<int> preorder(Node* root) {
        st.push(root);
        for(Node* cur=root; !st.empty(); cur=st.top(),st.pop()){
            if(cur==NULL) continue;
            sol.push_back(cur->val);
            for(int i=(int)cur->children.size()-1; i>=0&&cur->children[i]; --i) {
                st.push(cur->children[i]);
            }
        }
        return sol;
    }
};
*/