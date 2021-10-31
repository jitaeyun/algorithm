/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur=head;
        stack<Node*> st;
        while(cur){
            if(cur->child) {
                if(cur->next) st.push(cur->next); 
                cur->next=cur->child;
                cur->next->prev=cur;
                cur->child=nullptr;
            }
            else if(cur->next==nullptr && !st.empty()) {
                cur->next=st.top(); st.pop();
                cur->next->prev=cur;
            }
            cur=cur->next;
        }
        return head;
    }
};