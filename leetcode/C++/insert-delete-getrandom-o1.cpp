class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int,int> um;
    int t,a_idx,b_idx;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(um.find(val)!=um.end()) return false;
        um[val]=v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(um.find(val)==um.end()) return false;
        a_idx = um[val];
        b_idx = (int)v.size()-1;
        um[v[b_idx]]=a_idx;
        v[a_idx]=v[b_idx];
        v.pop_back();
        um.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */