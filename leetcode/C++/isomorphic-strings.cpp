class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> v(128,'\0');
        vector<int> count(128,1);
        if(s.length()!=t.length()) return false;
        for(int i; i<s.length(); ++i){
            if(v[s[i]]=='\0') {
                if(count[t[i]]--==0) return false;
                v[s[i]]=t[i];
            }
            if(v[s[i]]!=t[i]) return false;
        }
        return true;
    }
};