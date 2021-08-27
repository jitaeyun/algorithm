class Solution {
public:
    bool isSubsequence(string &a, string &b){
        int idx=0;
        for(int i=0; i<b.length()&&idx<a.length(); ++i) if(a[idx]==b[i]) ++idx;
        return idx==a.length();
    }
    int findLUSlength(vector<string>& strs) {
        int sol=-1;
        for(int i=0,j=0; i<strs.size(); ++i){
            for(j=0; j<strs.size(); ++j){
                if(i!=j&&isSubsequence(strs[i],strs[j])) break;
            }
            if(j==strs.size()) sol=max(sol,(int)strs[i].length());
        }
        return sol;
    }
};