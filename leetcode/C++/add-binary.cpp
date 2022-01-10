class Solution {
public:
    string addBinary(string a, string b) {
        string sol;
        int i=a.length()-1,j=b.length()-1,c=0;
        for(; i>=0 && j>=0; --i,--j){
            sol.push_back((a[i]+b[j]-'0'-'0'+c)%2+'0');
            c=(a[i]+b[j]-'0'-'0'+c)/2;
        }
        for(; i>=0; --i){
            sol.push_back((a[i]-'0'+c)%2+'0');
            c=(a[i]-'0'+c)/2;
        }
        for(; j>=0; --j){
            sol.push_back((b[j]-'0'+c)%2+'0');
            c=(b[j]-'0'+c)/2;
        }
        if(c) sol.push_back('1');
        reverse(sol.begin(), sol.end());
        return sol;
    }
};