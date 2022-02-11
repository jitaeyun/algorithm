class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v(26,0);
        for(char &ch : s1) ++v[ch-'a'];
        for(int l=0,r=0,idx=0; r<s2.length(); ++r){
            idx = s2[r]-'a';
            while(v[idx]==0 && l<r) ++v[s2[l++]-'a'];
            (v[idx]>0)? --v[idx] : ++l;
            if(r-l+1 == (int)s1.length()) return true;
        }
        return false;
    }
};