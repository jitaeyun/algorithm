class Solution {
public:
    bool validPalindrome(string s) {
        int i=0, j=(int)s.length()-1,a=0,b=0;
        for(; i<j; ++i,--j) if(s[i]!=s[j]) break;
        for(a=i+1,b=j; a<b; ++a,--b) if(s[a]!=s[b]) break;
        if(a>=b) return true;
        for(a=i,b=j-1; a<b; ++a,--b) if(s[a]!=s[b]) break;
        return a>=b;
    }
};