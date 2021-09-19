class Solution {
public:
    int numDistinct(string s, string t) {
        vector<unsigned int> dp(t.length()+1,0); dp[0]=1;
        if(s.length()<=t.length()) return (s==t)? 1 : 0;
        for(int i=0; i<s.length(); ++i){
            for(int j=min(i,(int)t.length()-1); j>=0; --j){
                if(t[j]==s[i]) dp[j+1]+=dp[j];
            }
        }
        return dp[t.length()];
    }
};