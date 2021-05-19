class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sol=0,l=0,r=0;
        unordered_map<char,int> um;
        for(int i=0; i<s.length(); ++i,++r) {
            if(um.find(s[i])!=um.end()) l=max(l,um[s[i]]+1);
            um[s[i]]=i;
            sol=max(sol, r-l+1);
        }
        return sol;
    }
};