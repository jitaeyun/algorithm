class CombinationIterator {
public:
    int idx;
    vector<string> v;
    string s;
    void traverse(string &characters,int &combinationLength, int len){
        if(s.length()==combinationLength){
            v.push_back(s);
            return;
        }
        else if(characters.length()<=len) return;
        s.push_back(characters[len]);
        traverse(characters, combinationLength, len+1);
        s.pop_back();
        traverse(characters, combinationLength, len+1);
    }
    CombinationIterator(string characters, int combinationLength) {
        idx=0;
        traverse(characters, combinationLength, 0);
    }

    string next() {
        return v[idx++];
    }
    
    bool hasNext() {
        return idx<v.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */