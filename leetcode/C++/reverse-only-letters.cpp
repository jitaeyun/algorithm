class Solution {
public:
    bool isalphabet(char &c){
        if((c>='a'&&c<='z') || (c>='A'&&c<='Z')) return true;
        return false;
    }
    string reverseOnlyLetters(string s) {
        string sol=s;
        for(char &c : sol) if(isalphabet(c)) c=0;
        for(int i=0,j=s.length()-1; i<s.length() && j>=0;){
            while(i<sol.length() && sol[i]!=0) ++i;
            while(j>=0 && !isalphabet(s[j])) --j;
            if(i<s.length() && j>=0) sol[i++]=s[j--];
        }
        return sol;
    }
};