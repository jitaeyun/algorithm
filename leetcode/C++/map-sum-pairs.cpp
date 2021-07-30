class Trie{
public:
    int n;
    Trie *next;
    Trie(): n(0), next(nullptr) {}
};

class MapSum {
public:
    /** Initialize your data structure here. */
    Trie *node;
    unordered_map<string,int> um;
    MapSum() {node=new Trie();}
    
    void insert(string key, int val) {
        int idx=0, diff=val-um[key];
        um[key]=val;
        Trie* cur=node;
        for(char &ch : key){
            if(cur->next==nullptr) cur->next=new Trie[26];
            cur->next[ch-'a'].n+=diff;
            cur=&(cur->next[ch-'a']);
        }
    }
    
    int sum(string prefix) {
        int sol=0;
        Trie* cur=node;
        for(char &ch : prefix){
            if(cur->next==nullptr || cur->next[ch-'a'].n==0) {
                sol=0;
                break;
            }         
            sol=cur->next[ch-'a'].n;
            cur=&(cur->next[ch-'a']);
        }
        return sol;
    }
};

/*
class MapSum {
public:
    unordered_map<string,int> um, um_str;
    void insert(string key, int val) {
        int diff=val-um_str[key];
        string s;
        um_str[key]=val;
        for(char &ch : key){
            s.push_back(ch);
            um[s]+=diff;
        }
    }
    int sum(string prefix) {
        return um[prefix];
    }
};
 */