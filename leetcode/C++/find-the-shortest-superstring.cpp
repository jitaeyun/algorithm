class Solution {
public:
    string t;
    vector<string> dp[12];
    vector<vector<int>> overlaps;
    void tsp(vector<string>& words, int cur, int visit){
        string sol;
        if(!dp[cur][visit].empty()) return;
        else if(visit==(1<<cur)){
            dp[cur][visit]=words[cur];
            return;
        }
        for(int i=0; i<words.size(); ++i){
            if((visit & (1<<i)) == 0 || i==cur) continue;
            tsp(words, i, visit^(1<<cur));
            t=words[cur].substr(0,overlaps[cur][i])+dp[i][visit^(1<<cur)];
            if(sol.length()==0 || sol.length()>t.length()) sol=t;
        }
        dp[cur][visit]=sol;
    }
    string shortestSuperstring(vector<string>& words) {
        string sol;
        int mx=(1<<words.size())-1;
        for(int i=0; i<words.size(); ++i) dp[i]=vector<string>(mx+1);
        overlaps=vector<vector<int>>(words.size(),vector<int>(words.size()));
        //calc overlap string
        for(int i=0; i<words.size(); ++i){
            for(int j=0; j<words.size(); ++j){
                if(i==j) continue;
                overlaps[i][j]=words[i].length();
                int k = (words[i].length()<words[j].length())? 0 : words[i].length()-words[j].length();
                for(; k<words[i].length(); ++k){
                    if(words[i].substr(k)==words[j].substr(0,words[i].length()-k)){
                        overlaps[i][j]=k;
                        break;
                    }
                }
            }
        }
        //traverse
        for(int i=0; i<words.size(); ++i) {
            tsp(words,i,mx);
            if(sol.empty() || sol.length() > dp[i][mx].length()) sol=dp[i][mx];
        }
        return sol;
    }
};