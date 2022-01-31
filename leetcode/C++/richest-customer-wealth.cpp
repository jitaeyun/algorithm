class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sol = 0, mx = 0;
        for(vector<int> &account : accounts){
            mx = 0;
            for(int &amount : account) mx += amount;
            sol = max(sol, mx);
        }
        return sol;
    }
};