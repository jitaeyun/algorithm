class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones=0, zeros=0, idx;
        for(char &ch: s){
            idx=ch-'0';
            ones = min(zeros, ones)+(idx^1);
            zeros = zeros+idx;
        }
        return min(ones, zeros);
    }
};