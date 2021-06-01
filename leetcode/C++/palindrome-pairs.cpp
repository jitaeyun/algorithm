class TrieNode {
public:
    int idx;
    unordered_set<int> us;
    unordered_map<char,TrieNode*> um;
    TrieNode() {idx=-1;}
};

class Trie {
public:
    TrieNode *node;
    Trie() {node=new TrieNode();}
    bool palindrome(string &w,int &s, int &l){
        for(int i=0; i<(l-s)/2; ++i){
            if(w[s+i]!=w[l-1-i]) return false;
        }
        return true;
    }
    void insert(int &idx, string &w){
        TrieNode *cur = node;
        int s=0;
        for(int i=w.length(); i>0; --i){
            if(palindrome(w,s, i)) {
                cur->us.insert(idx);
            }
            if(cur->um.find(w[i-1])==cur->um.end()){
                cur->um[w[i-1]]=new TrieNode();
            }
            cur=cur->um[w[i-1]];
        }
        cur->idx=idx;
    }
    void search(int &idx, string &w, vector<vector<int>> &res){
        TrieNode *cur = node;
        int sz = w.length();
        for(int i=0; i<w.length(); ++i){
            if(cur->idx >= 0){
                if(palindrome(w,i,sz)){
                    res.push_back({idx, cur->idx});
                }
            }
            if(cur->um.find(w[i])==cur->um.end()) return;
            cur=cur->um[w[i]];
        }
        if(cur->idx >= 0 && cur->idx != idx){
            res.push_back({idx, cur->idx});
        }
        for(const int &t : cur->us){
            res.push_back({idx,t});
        }
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> sol;
        Trie trie = Trie();
        for(int i=0; i<words.size(); ++i) {
            trie.insert(i,words[i]);
        }
        for(int i=0; i<words.size(); ++i){
            trie.search(i, words[i], sol);
        }
        return sol;
    }
};