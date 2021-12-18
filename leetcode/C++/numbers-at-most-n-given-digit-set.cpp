class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string num = to_string(n);
        int sol=0;
        vector<int> digit(10,0), mn(10,0), mul(10,1);
        for(string &s : digits) ++digit[stoi(s)];
        for(int i=1; i<=9; ++i) {
            mn[i]=mn[i-1]+digit[i];
            if(i==1) mul[i]=digits.size();
            else mul[i]=mul[i-1]*(digits.size());
        }
        if(digits.size()>1) sol = (digits.size()*(mul[num.length()-1]-1))/(digits.size()-1);
        else sol = num.length()-1;
        for(int i=0,idx=0; i<num.length(); ++i){
            idx=num[i]-'0';
            sol+=(mn[idx]-digit[idx])*mul[num.length()-1-i];
            if(i+1==num.length()) sol+=digit[idx];
            else if(digit[idx]==0) break;
        }
        return sol;
    }
};