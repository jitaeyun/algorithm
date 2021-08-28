class POINT {
public:
    int s,e,p;
};
class Solution {
public:
    int binarySearch(vector<POINT> &v, vector<int> &dp, int &e){
        int l=0,r=e-1,m=0;
        while(l<=r){
            m=(l+r)/2;
            if(v[m].e<=v[e].s) l=m+1;
            else r=m-1;
        }
        return (l>=1)? dp[l-1] : 0;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<POINT> v;
        vector<int> dp = vector<int>(profit.size(),0);
        for(int i=0; i<profit.size(); ++i) v.push_back({startTime[i], endTime[i], profit[i]});
        sort(v.begin(), v.end(), [](POINT &a, POINT &b){return a.e<b.e;});
        for(int i=0; i<v.size(); ++i){
            if(i>0) dp[i]=dp[i-1];
            dp[i]=max(dp[i],binarySearch(v,dp,i)+v[i].p);
        }
        return dp.back();
    }
};