class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sol=0,sum=0, sz=cardPoints.size();
        for(int i=0; i<k; ++i) sum+=cardPoints[sz-i-1];
        sol=sum;
        for(int i=0; i<k; ++i){
            sum+=cardPoints[i]-cardPoints[sz-k+i];
            sol=max(sol,sum);
        }
        return sol;
    }
};