class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int sol = 0, last_idx = -1;
        for(int i=0; i<seats.size(); ++i){
            if(seats[i] == 0) continue;
            else if(last_idx == -1) sol = i; // before first_idx case
            else sol = max(sol, (i-last_idx)/2); //between case
            last_idx = i;
        }
        // after last_idx case
        return max(sol, (int)seats.size()-last_idx-1);
    }
};


//another solution
/*
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int sz = seats.size();
        int sol = 0;
        vector<int> dp(sz,sz);
        for(int i=0, p=-1; i<sz; ++i){
            if(seats[i]) p=i;
            else if(p>-1) dp[i] = i-p;
        }
        for(int i=(int)seats.size()-1, p=-1; i>=0; --i){
            if(seats[i]) p=i;
            else if(p > -1) dp[i] = min(dp[i], p-i);
            if(seats[i] ==0) sol = max(sol, dp[i]);
            
        }
        return sol;
    }
};
*/