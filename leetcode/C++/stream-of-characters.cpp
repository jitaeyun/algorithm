class TRIE {
    int w;
    vector<TRIE*> t;
public:
    TRIE() : w(0), t(vector<TRIE*>(26,nullptr)) {}
    TRIE* addNode(char &ch){
        int idx=ch-'a';
        if(t[idx]==nullptr) t[idx]=new TRIE();
        return t[idx];
    }
    TRIE* nextNode(char &ch){
        int idx=ch-'a';
        return t[idx];
    }
    void addWord() {++w;}
    bool isWord() {return w>0;}
};

class StreamChecker {
public:
    TRIE* trie;
    string letters;
    StreamChecker(vector<string>& words) {
        trie = new TRIE();
        TRIE *cur = nullptr;
        for(string &word: words){
            cur = trie;
            for(int i=(int)word.length()-1; i>=0; --i) cur=cur->addNode(word[i]);
            cur->addWord();
        }
    }
    
    bool query(char letter) {
        TRIE *cur = trie;
        letters.push_back(letter);
        for(int i=(int)letters.length()-1; i>=0; --i){
            cur=cur->nextNode(letters[i]);
            if(cur==nullptr) return false;
            else if(cur->isWord()) return true;
        }
        return cur->isWord();
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */