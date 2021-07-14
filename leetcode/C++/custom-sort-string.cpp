class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> visit(26,0);
        string sol;
        for(char &ch : str) ++visit[ch-'a'];
        for(char &ch : order){
            for(int i=0; i<visit[ch-'a']; ++i) sol.push_back(ch);
            visit[ch-'a']=0;
        }
        for(int i=0; i<visit.size(); ++i){
            for(int j=0; j<visit[i]; ++j) sol.push_back('a'+i);
        }
        return sol;
    }
};