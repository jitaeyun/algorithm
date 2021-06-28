class Solution {
public:
    string removeDuplicates(string s) {
        string sol;
        for(char &ch : s){
            if(sol.empty() || sol.back()!=ch) {
                sol.push_back(ch);
                continue;
            }
            while(!sol.empty() && sol.back()==ch) sol.pop_back();
        }
        return sol;
    }
};