class Solution {
public:
    int subsolve(vector<int>& nums, vector<vector<int>> &dp, int l, int r){
        int mx=0;
        if(l>r) return 0;
        else if(dp[l][r]>-1) return dp[l][r];
        int a = (l==0)? 1 : nums[l-1];
        int b = (r+1==nums.size())? 1 : nums[r+1];
        for(int i=l; i<=r; ++i){
            mx = max(mx, nums[i]*a*b+subsolve(nums,dp,l, i-1)+subsolve(nums,dp, i+1, r));
        }
        return dp[l][r]=mx;
    }
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(),-1));
        return subsolve(nums, dp, 0, nums.size()-1);
    }
};

/*
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(),0));
        int a=0,b=0,v=0;
        for(int d=0; d<nums.size(); ++d){
            for(int s=0; s+d<nums.size(); ++s){
                a = (s==0)? 1 : nums[s-1];
                b = (s+d+1==nums.size())? 1 : nums[s+d+1];
                for(int i=s; i<=s+d; ++i){
                    v=0;
                    if(i-1>=s) v+=dp[s][i-1];
                    if(i+1<=s+d) v+=dp[i+1][s+d];
                    v+=a*b*nums[i];
                    dp[s][s+d]=max(dp[s][s+d], v);
                }
            }
        }
        return dp[0][nums.size()-1];
    }
};
*/

/*
매우 어려웠던 문제
dp로 풀어야 겠다는 생각은 했지만, 숫자가 중간에 빠질 수 있으므로 (burst)
dp[i:j]는 구할수 없다고 생각 했음
그래서 전체 visit/non visit으로 생각했으나 이러면 당연히 타임 리밋;; ㅡㅡ;
역발상이 필요한데 순차대로 burst를 시킬 필요가 없음. 가장 마지막에 burst 시킬 수 를 뽑아도 구하는 값이 달라지지 않음
즉, 가장 마지막에 burst할 수를 뽑아 놓으면 dp[i:j] 가 성립함
dp[i:j] = nums[k]*nums[i-1]*nums[j+1] + dp[i:k-1] + dp[k+1:j] 이게 성립함
마지막까지 k가 살아있기 때문에 dp[i:k-1] // dp[k+1:j]를 망치지 않으며 결과를 망치치 않음
subproblem으로 나눌 수 있음
*/