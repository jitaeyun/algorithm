class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int r = matrix.size(), c = matrix[0].size(), curSum=0, sol = -1000000;
        set<int>::iterator it;
        vector<vector<int>> sumMatrix;
        for(int i=0; i<r; ++i){
            vector<int> sub;
            for(int j=0; j<c; ++j){
                if(sub.empty()) sub.push_back(matrix[i][j]);
                else sub.push_back(sub.back()+matrix[i][j]);
            }
            sumMatrix.push_back(sub);
        }
        for(int i=0; i<c; ++i){
            for(int j=i; j<c; ++j){
                curSum=0;
                set<int> s;
                s.insert(0);
                for(int l=0; l<r; ++l){
                    curSum+=sumMatrix[l][j];
                    if(i>0) curSum-=sumMatrix[l][i-1];
                    it = s.lower_bound(curSum-k);
                    if(it!=s.end()) sol=max(sol,curSum-*it);
                    s.insert(curSum);
                }
            }
        }
        return sol;
    }
};