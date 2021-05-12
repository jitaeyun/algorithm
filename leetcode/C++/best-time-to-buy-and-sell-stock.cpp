class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sol=0, mn=INT_MAX;
        for(const int & p : prices){
            sol=max(sol,p-mn);
            mn=min(mn,p);
        }
        return sol;
    }
};