/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> um;
        vector<Node*> v;
        int idx=0;
        for(Node* cur=head, *t=nullptr; cur; cur=cur->next) {
            um[cur]=idx++;
            t = new Node(cur->val);
            if(!v.empty()) v.back()->next = t;
            v.push_back(t);
        }
        idx=0;
        for(Node* cur=head; cur; cur=cur->next,++idx) if(cur->random) v[idx]->random=v[um[cur->random]];
        return (!v.empty())? v[0] : nullptr;
    }
};