class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string sol;
        vector<int> deletedIdx, plusIdx;
        int acc=0;
        for(int i=0; i<s.length(); ++i){
            if(s[i]=='(') {++acc; plusIdx.push_back(i);}
            else if(s[i]==')') {
                if(acc<=0) deletedIdx.push_back(i);
                else --acc;
            }
        }
        for(int i=0,j=0; i<s.length(); ++i){
            if(j<deletedIdx.size() && deletedIdx[j]==i) ++j;
            else if(j>=deletedIdx.size() && acc>0 && plusIdx[plusIdx.size()-acc]==i) --acc;
            else sol.push_back(s[i]);
        }
        return sol;
    }
};