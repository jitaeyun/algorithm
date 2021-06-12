class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sol = 0, s=-prices[0], b=0;
        for(int i=1; i<prices.size(); ++i){
            b=max(b, s+prices[i]);
            s=max(s, b-prices[i]);
            sol=max(sol,b);
        }
        return sol;
    }
};