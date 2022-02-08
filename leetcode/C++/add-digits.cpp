class Solution {
public:
    int addDigits(int num) {
        int n=num;
        string s;
        while(n>=10){
            s=to_string(n); n=0;
            for(char &ch : s) n+=ch-'0';
        }
        return n;
    }
};