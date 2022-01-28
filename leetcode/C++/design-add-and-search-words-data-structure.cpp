class TRIE{
public:
    unordered_map<char, TRIE*> um;
    int count;
    TRIE () {count=0;}
    void makeTrie(string &s){
        TRIE* t = this;
        for(char &ch : s){
            if(t->um.find(ch)==um.end()) t->um[ch] = new TRIE();
            t = t->um[ch];
        }
        ++t->count;
    }
};

class WordDictionary {
public:
    TRIE* t;
    /** Initialize your data structure here. */
    WordDictionary() {
        t = new TRIE();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        t->makeTrie(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return traverse(t, word, 0);
    }
    bool traverse(TRIE *t, string &word, int idx){
        TRIE *r = t;
        for(int i=idx; i<word.length(); ++i){
            if(r==nullptr) return false;
            else if(word[i]=='.') {
                for(const pair<char, TRIE*> p : r->um){
                    if(traverse(p.second, word, i+1)) return true;
                }
                return false;
            }
            else if(r->um.find(word[i]) == r->um.end()) return false;
            r = r->um[word[i]];
        }
        return r->count>0;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */