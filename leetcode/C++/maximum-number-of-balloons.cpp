class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int sol=10000;
        string s = "balon";
        unordered_map<char,int> um;
        for(char & c : text) ++um[c];
        for(char & c : s) {
            if(c=='l' || c=='o') sol=min(sol,um[c]/2);
            else sol=min(sol,um[c]);
        }
        return sol;
    }
};