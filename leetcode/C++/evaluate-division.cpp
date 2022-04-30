class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int g = 1, a=0, b=0;
        double val = 0;
        unordered_map<string,int> um;
        vector<vector<double>> dp;
        vector<double> sol;
        // 1. make graph
        for(vector<string> &e : equations) {
            for(string &s : e) if(um.find(s)==um.end()) um[s] = g++;
        }
        dp = vector<vector<double>>(g, vector<double>(g, -1.0));
        for(int i=0; i<equations.size(); ++i){
            a=um[equations[i][0]]; b=um[equations[i][1]];
            dp[a][b] = values[i];
            dp[b][a] = 1.0/values[i];
            dp[a][a] = dp[b][b] = 1.0;
        }
        // 2. traverse
        for(int k=0; k<g; ++k){
            for(int i=0; i<g; ++i){
                for(int j=0; j<g; ++j){
                    if(dp[i][k] <0 || dp[k][j] < 0) continue;
                    else if(dp[i][j] > 0) continue;
                    dp[i][j] = dp[i][k]*dp[k][j];
                }
            }
        }
        // 3. calc equation
        for(vector<string> &q : queries){
            a=um[q[0]]; b=um[q[1]];
            sol.push_back(dp[a][b]);
        }
        return sol;
    }
};