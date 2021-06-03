class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        string sol;
        for(int &n : nums) v.push_back(to_string(n));
        sort(v.begin(),v.end(),[](string &a, string &b){return a+b>b+a;});
        for(string &s : v) sol+=s;
        if(sol[0]=='0') return "0";
        return sol;
    }
};