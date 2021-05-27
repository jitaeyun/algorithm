/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    queue<TreeNode*> q;
    TreeNode* t;
    string s;
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* n) {
        if(!n) return s;
        q.push(n);
        while(!q.empty()){
            t=q.front(); q.pop();
            if(!t) {
                s+=",n";
                continue;
            }
            else if(!s.empty()) s.push_back(',');
            s+=to_string(t->val);
            q.push(t->left);
            q.push(t->right);
        }
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int state=0;
        if(data.empty()) return NULL;
        stringstream ss(data);
        while(getline(ss,s,',')){
            if(q.empty()) {
                q.push((t=new TreeNode(stoi(s))));
                continue;
            }
            else if(s!="n") {
                if(state==0) q.push((q.front()->left=new TreeNode(stoi(s))));
                else q.push((q.front()->right=new TreeNode(stoi(s))));
            }
            if(state++) q.pop();
            state%=2;
        }
        return t;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));