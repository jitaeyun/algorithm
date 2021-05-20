class Solution {
public:
    vector<string> sol;
    vector<string> v = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string cur;
    void traverse(int idx, string &digits){
        if(idx==digits.length()) {
            sol.push_back(cur);
            return;
        }
        for(char &ch : v[digits[idx]-'2']){
            cur.push_back(ch);
            traverse(idx+1, digits);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return sol;
        traverse(0,digits);
        return sol;
    }
};