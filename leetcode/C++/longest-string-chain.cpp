class Solution {
public:
    bool checkPredecessor(string &s, string &ls){
        for(int i=0,j=0,d=0; i<s.length(); ++i,++j){
            if(s[i]!=ls[j]){
                --i;
                if(d++) return false;
            }
        }
        return true;
    } 
    int longestStrChain(vector<string>& words) {
        int sol=1;
        vector<int> acc(words.size(),1);
        sort(words.begin(),words.end(),[](const string &a, const string &b){return a.length()<b.length();});
        for(int i=0; i<words.size(); ++i){
            for(int j=i+1,t; j<words.size()&&words[j].length()<=words[i].length()+1; ++j){
                if(words[j].length()==words[i].length()) continue;
                if(acc[i]+1 > acc[j] && checkPredecessor(words[i],words[j])){
                    acc[j]=acc[i]+1;
                    if(sol<acc[j]) sol=acc[j];
                }
            }
        }
        return sol;
    }
};