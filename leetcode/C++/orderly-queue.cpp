class Solution {
public:
    string orderlyQueue(string s, int k) {
        string m=s;
        if(k==1) {
            for(int i=0; i<s.length()-1; ++i){
                s=s.substr(1)+s[0];
                if(s<m) m=s;
            }
        }
        else sort(m.begin(),m.end());
        return m;
    }
};