class Solution {
public:
    vector<int> v[26];
    bool binary_search(string &w){
        int c=-1, t=0, idx=0,l=0,r=0,m=0;
        for(char &ch: w){
            idx=ch-'a';
            if(v[idx].empty()) return false;
            l=0; r=v[idx].size()-1; t=-1;
            while(l<=r && v[idx][r]>c){
                m=(l+r)/2;
                if(v[idx][m]<=c) l=m+1;
                else {
                    t=v[idx][m];
                    r=m-1;
                }
            }
            if(t<=c) return false;
            c=t;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int sol=0;
        for(int i=0; i<s.length(); ++i) v[s[i]-'a'].push_back(i);
        for(string &w : words) if(binary_search(w)) ++sol;
        return sol;
    }
};