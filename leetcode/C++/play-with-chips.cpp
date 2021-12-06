class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd=0,even=0;
        for(int &n : position){
            if((n&1)==1) ++odd;
            else ++even;
        }
        return min(odd,even);
    }
};