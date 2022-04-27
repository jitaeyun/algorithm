class Solution {
public:
    vector<int> p;
    int find(int &a){
        if(p[a]==-1) return a;
        return p[a]=find(p[a]);
    }
    void unions(int a, int b){
        a =find(a); b=find(b);
        if(a==b) return;
        p[a]=b;
    }
    void stringSorting(string &s, vector<int> &alphabet, const vector<int> &group){
        for(const int &idx : group) ++alphabet[s[idx]-'a'];
        for(int i=0, idx=0; i<26; ++i){
            for(int j=0; j<alphabet[i]; ++j) s[group[idx++]]='a'+i;
            alphabet[i] = 0;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> um;
        vector<int> alphabet(26,0);
        p = vector<int>(s.length(),-1);
        //1. disjoint
        for(vector<int> &p : pairs) unions(p[0],p[1]);
        //2. group num and make group
        for(int i=0; i<s.length(); ++i) um[find(i)].push_back(i);
        //3. sort
        for(const pair<int,vector<int>> &v : um) stringSorting(s, alphabet, v.second);
        //4. return
        return s;
    }
};