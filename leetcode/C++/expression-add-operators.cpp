class Solution {
public:
    vector<string> dp[10];
    vector<long> output[10];
    vector<long> prev[10];
    vector<long> last_num[10]; //abs
    vector<int> last_op[10]; //0:+ 1:- 2:*
    void addOperation(string &num, int &idx) {
        if(idx==0) {
            dp[idx].push_back(to_string(num[idx]-'0'));
            output[idx].push_back(num[idx]-'0');
            prev[idx].push_back(num[idx]-'0');
            last_num[idx].push_back(num[idx]-'0');
            last_op[idx].push_back(0);
        }
        long p,o,ln,lo;
        for(int i=0; idx>0 && i<dp[idx-1].size(); ++i){
            o=output[idx-1][i]; p=prev[idx-1][i]; ln=last_num[idx-1][i]; lo=last_op[idx-1][i];
            // 1. +
            dp[idx].push_back(dp[idx-1][i]+"+"+num[idx]);
            prev[idx].push_back(num[idx]-'0');
            output[idx].push_back(o+num[idx]-'0');
            last_num[idx].push_back(num[idx]-'0');
            last_op[idx].push_back(0);
            // 2. -
            dp[idx].push_back(dp[idx-1][i]+"-"+num[idx]);
            prev[idx].push_back(-(num[idx]-'0'));
            output[idx].push_back(o-(num[idx]-'0'));
            last_num[idx].push_back(num[idx]-'0');
            last_op[idx].push_back(1);
            // 3. *
            dp[idx].push_back(dp[idx-1][i]+"*"+num[idx]);
            prev[idx].push_back(p*(num[idx]-'0'));
            output[idx].push_back(o+prev[idx].back()-p);
            last_num[idx].push_back(num[idx]-'0');
            last_op[idx].push_back(2);
            // 4. 붙이기
            // 4.1 이전 op가 +
            if(ln==0) continue;
            dp[idx].push_back(dp[idx-1][i]+num[idx]);
            last_num[idx].push_back(ln*10+(num[idx]-'0'));
            last_op[idx].push_back(lo);
            if(lo==0) prev[idx].push_back(p*10+(num[idx]-'0'));
            // 4.2 이전 op가 -
            else if(lo==1) prev[idx].push_back(p*10-(num[idx]-'0'));
            // 4.3 이전 op가 *
            else prev[idx].push_back(p/ln*(10*ln+num[idx]-'0'));
            output[idx].push_back(o+prev[idx].back()-p);
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> sol;
        for(int i=0; i<num.length(); ++i) addOperation(num,i);
        for(int i=0; i<dp[num.length()-1].size(); ++i){
            if(output[num.length()-1][i]==target){
                sol.push_back(dp[num.length()-1][i]);
            }
        }
        return sol;
    }
};