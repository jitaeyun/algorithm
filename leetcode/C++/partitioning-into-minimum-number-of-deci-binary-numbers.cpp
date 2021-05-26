class Solution {
public:
    int minPartitions(string n) {
        int sol=0;
        for(char &ch : n) sol=max(sol,ch-'0');
        return sol;
    }
};