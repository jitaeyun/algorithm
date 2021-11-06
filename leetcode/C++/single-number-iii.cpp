class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0, idx=1, f=0;
        for(int &n : nums) x^=n;
        for(int i=0; i<31; ++i, idx<<=1) if((idx&x)>0) break;
        for(int &n : nums) if((n&idx)>0) f^=n;
        return {f, f^x};
    }
};