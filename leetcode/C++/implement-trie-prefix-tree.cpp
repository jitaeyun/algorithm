class Trie {
    int count;
    int end;
    Trie *t;
public:
    /** Initialize your data structure here. */
    Trie() {
        count=end=0;
        t=NULL;
    }
    
    Trie* makeTrie(){
        Trie* trie=new Trie[26];
        return trie;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *cur=this;
        ++cur->count;
        for(int i=0,idx=0; i<word.length(); ++i){
            idx=word[i]-'a';
            if(cur->t==NULL) cur->t=makeTrie();
            ++cur->t[idx].count;
            cur=&cur->t[idx];
        }
        ++cur->end;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *cur=this;
        int idx=0,count=0;
        for(int i=0; i<word.length(); ++i){
            idx=word[i]-'a';
            if(cur->t==NULL || cur->t[idx].count==0) return false;
            cur=&cur->t[idx];
        }
        return cur->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *cur=this;
        int idx=0;
        for(char &ch : prefix){
            idx=ch-'a';
            if(cur->t==NULL || cur->t[idx].count==0) return false;
            cur=&cur->t[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */