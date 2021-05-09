class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(const char &c: s){
            if('a'<=c && c<='z' || '0'<=c && c<='9') t.push_back(c);
            else if('A'<=c && c<='Z') t.push_back(c-'A'+'a');
        }
        for(int i=0; i<t.length()/2; ++i) if(t[i]!=t[t.length()-i-1]) return false;
        return true;
    }
};