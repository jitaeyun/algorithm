class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sol = 0;
        long long j = 1;
        for(int i=(int)columnTitle.length()-1; i>=0; --i,j*=26){
            sol += (columnTitle[i]-'A'+1)*j;
        }
        return sol;
    }
};