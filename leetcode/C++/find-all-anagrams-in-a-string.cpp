class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sol,v(26,0);
        for(char &ch : p) ++v[ch-'a'];
        for(int l=0,r=0; r<s.length();){
            while(l<r && v[s[r]-'a'] == 0) ++v[s[l++]-'a'];
            if(v[s[r]-'a']==0) {++l; ++r;}
            else --v[s[r++]-'a'];
            if(r-l == p.length()) {
                sol.push_back(l);
                ++v[s[l++]-'a'];
            }
        }
        return sol;
    }
};