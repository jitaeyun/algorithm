class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> trans;
        int n=0, sol=0;
        for(string &s : words){
            n=0;
            for(char &ch : s) n|=(1<<(ch-'a'));
            trans.push_back(n);
        }
        for(int i=0; i<trans.size(); ++i){
            for(int j=i+1; j<trans.size(); ++j){
                if((trans[i]&trans[j])) continue;
                sol=max(sol,(int)words[i].length()*(int)words[j].length());
            }
        }
        return sol;
    }
};