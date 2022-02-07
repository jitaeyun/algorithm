class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26,0);
        for(char &ch : s) ++v[ch-'a'];
        for(char &ch : t) if(--v[ch-'a']<0) return ch;
        return t.back();
    }
};