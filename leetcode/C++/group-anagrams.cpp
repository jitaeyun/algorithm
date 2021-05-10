class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string t;
        unordered_map<string,vector<string>> um;
        vector<vector<string>> sol;
        for(string &s : strs){
            t=s;
            sort(t.begin(),t.end());
            um[t].push_back(s);
        }
        for(const pair<string,vector<string>>& p : um) sol.push_back(p.second);
        return sol;
    }
};