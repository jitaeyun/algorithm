class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperLen = 0;
        for(char &ch : word) {if(ch>='A' && ch<='Z') ++upperLen;}
        return (upperLen == word.length()) || (upperLen==1 && word[0]>='A' && word[0]<='Z') || (upperLen == 0);
    }
};