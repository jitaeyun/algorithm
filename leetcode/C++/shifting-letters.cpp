class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int shift=0;
        for(int i=0; i<s.length(); ++i) {
            shifts[i]%=26;
            shift=(shift+shifts[i])%26;
        }
        for(int i=0; i<s.length(); ++i){
            s[i]='a'+(s[i]-'a'+shift)%26;
            shift-=shifts[i];
            if(shift<0) shift+=26;
        }
        return s;
    }
};