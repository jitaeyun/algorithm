class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int sol=0;
        vector<int> v(60,0);
        for(int &t : time) ++v[t%60];
        for(int i=0,j=60; i<=j; ++i,--j){
            if(i==0 || i==j) sol+=(v[i]*(v[i]-1))/2;
            else sol+=v[i]*v[j];
        }
        return sol;
    }
};