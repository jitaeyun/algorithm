class Solution {
public:
    string breakPalindrome(string palindrome) {
        bool solved=false;
        for(int i=0,j=palindrome.length()-1; i<palindrome.length()&&i<j; ++i,--j){
            if(palindrome[i]!='a') {
                palindrome[i]='a';
                solved=true;
                break;
            }
        }
        if(palindrome.length()<=1) palindrome="";
        else if(!solved) palindrome[palindrome.length()-1]='b';
        return palindrome;
    }
};