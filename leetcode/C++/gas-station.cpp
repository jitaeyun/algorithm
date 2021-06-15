class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int mIdx=0, s=0;
        for(int i=0,j=0; i<cost.size(); ++i){
            s+=gas[i]-cost[i];
            j+=gas[i]-cost[i];
            if(j<gas[i]-cost[i]){mIdx=i; j=gas[i]-cost[i];}
        }
        return (s<0)? -1 : mIdx;
    }
};