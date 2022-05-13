/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        int sz = 0;
        Node* prev=nullptr, *cur=nullptr;
        queue<Node*> q;
        if(root==nullptr) return root;
        q.push(root);
        while(!q.empty()){
            prev=nullptr;
            sz = q.size();
            for(int i=0; i<sz; ++i){
                cur=q.front(); q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                if(prev) prev->next=cur;
                prev=cur;
            }
        }
        return root;
    }
};