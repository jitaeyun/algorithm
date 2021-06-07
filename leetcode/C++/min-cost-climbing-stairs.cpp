class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int p1=cost[0],p2=cost[1],t=0;
        for(int i=2; i<cost.size(); ++i){
            t=min(p1,p2)+cost[i];
            p1=p2;
            p2=t;
        }
        return min(p1,p2);
    }
};