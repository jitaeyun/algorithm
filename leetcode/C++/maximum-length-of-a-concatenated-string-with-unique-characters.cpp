class Solution {
public:
    void conversion(string &s, vector<unsigned int> &v, vector<unsigned int> &v_lens){
        unsigned int bits=0;
        for(int i=0,bit=0; i<s.length(); ++i){
            bit=1<<(s[i]-'a');
            if((bits&bit)!=0) return;
            bits|=bit;
        }
        v.push_back(bits);
        v_lens.push_back(s.length());
    }
    int maxLength(vector<string>& arr) {
        int sol=0;
        vector<unsigned int> v,v_lens, dp, dp_lens;
        for(string &s : arr) conversion(s,v, v_lens);
        for(int i=0; i<v.size(); ++i){
            for(int j=(int)dp.size()-1; j>=0; --j){
                if((v[i]&dp[j])!=0) continue;
                dp.push_back(v[i]|dp[j]);
                dp_lens.push_back(v_lens[i]+dp_lens[j]);
                sol=max(sol,(int)dp_lens.back());
            }
            dp.push_back(v[i]);
            dp_lens.push_back(v_lens[i]);
            sol=max(sol,(int)dp_lens.back());
        }
        return sol;
    }
};