class Solution {
public:
    string getSmallestString(int n, int k) {
        string sol;
        for(int i=n, remain=k,val=0; i>0; --i){
            val = max(1, remain - 26*(i-1));
            remain -= val;
            sol.push_back(val+'a'-1);
        }
        return sol;
    }
};