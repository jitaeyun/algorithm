class Solution {
public:
    vector<int> nums, op;
    vector<int> dp[10][10];
    void parsing(string &expression){
        string s;
        for(char &ch : expression){
            if(ch>='0' && ch<='9') s.push_back(ch);
            else {
                nums.push_back(stoi(s)); s="";
                if(ch=='+') op.push_back(0);
                else if(ch=='-') op.push_back(1);
                else op.push_back(2);
            }
        }
        nums.push_back(stoi(s));
    }
    void subOperation(int &l, int &r){
        if(l==r) dp[l][r].push_back(nums[l]);
        for(int i=l,t=0; i<r; ++i){
            for(int &a : dp[l][i]) {
                for(int &b : dp[i+1][r]){
                    if(op[i]==0) t=a+b;
                    else if(op[i]==1) t=a-b;
                    else t=a*b;
                    dp[l][r].push_back(t);
                }
            }
        }
    }
    vector<int> diffWaysToCompute(string expression) {
        parsing(expression);
        for(int i=0; i<nums.size(); ++i)
            for(int l=0,r=i; r<nums.size(); ++l,++r)
                subOperation(l,r);
        return dp[0][nums.size()-1];
    }
};