class Solution {
public:
    vector<int> v;
    Solution *t;
    Solution(){t=NULL;}
    Solution* makeTrie(){return new Solution[26];}
    void insert(int &i, string &word){
        Solution *cur=this;
        int idx=0;
        this->v.push_back(i);
        for(char &ch : word){
            idx=ch-'a';
            if(cur->t==NULL) cur->t=makeTrie();
            cur->t[idx].v.push_back(i);
            cur=&cur->t[idx];
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> sol;
        Solution *cur = this;
        sort(products.begin(),products.end());
        for(int i=0; i<products.size(); ++i) insert(i,products[i]);
        for(char &ch : searchWord){
            vector<string> v;
            if(cur->t==NULL) {
                sol.push_back(v);
                continue;
            }
            cur=&cur->t[ch-'a'];
            for(int i=0; i<3 && i<cur->v.size(); ++i){
                v.push_back(products[cur->v[i]]);
            }
            sol.push_back(v);
        }
        return sol;
    }
};