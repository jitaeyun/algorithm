class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int answer=0, len = A.size();
        long long val=0;
        unordered_map<long long,int> m;
        for(int i=0; i<len; ++i){
            for(int j=0; j<len; ++j){
                ++m[A[i]+B[j]];
            }
        }
        for(int i=0; i<len; ++i){
            for(int j=0; j<len; ++j){
                val=C[i]+D[j];
                answer+=m[-val];
            }
        }
        return answer;
    }
};