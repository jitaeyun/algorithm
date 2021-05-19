class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int sol=0;
        unordered_set<char> us;
        for(char &ch : jewels) us.insert(ch);
        for(char &ch : stones){
            if(us.find(ch)!=us.end()) ++sol;
        }
        return sol;
    }
};