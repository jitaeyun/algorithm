class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sol=0, mn=prices[0];
        vector<int> mx(prices.size(),prices.back());
        if(prices.size()==1) return sol;
        for(int i=(int)prices.size()-2; i>=0; --i){
            mx[i] = max(mx[i+1],prices[i]);
            sol = max(sol,mx[i+1]-prices[i]);
        }
        for(int i=2, tr=prices[1]-prices[0]; i<(int)prices.size()-1; ++i){
            tr = max(tr,prices[i-1]-mn);
            mn = min(mn, prices[i-1]);
            sol = max(sol,tr + mx[i+1]-prices[i]);
        }
        return sol;
    }
};