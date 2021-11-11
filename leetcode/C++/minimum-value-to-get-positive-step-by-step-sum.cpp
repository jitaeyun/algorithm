class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int s=1,t=0;
        for(int &n : nums) {
            t+=n;
            s=min(s,t);
        }
        return (s<0)? 1-s : 1;
    }
};