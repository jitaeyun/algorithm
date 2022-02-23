/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        vector<Node*> store(101,nullptr);
        Node* ori=nullptr;
        queue<Node*> q;
        q.push(node);
        store[node->val] = new Node(node->val);
        while(!q.empty()){
            ori = q.front(); q.pop();
            for(Node* now : ori->neighbors){
                if(store[now->val]==nullptr) {
                    store[now->val] = new Node(now->val);
                    q.push(now);
                }
                store[ori->val]->neighbors.push_back(store[now->val]);
            }
        }
        return store[node->val];
    }
};