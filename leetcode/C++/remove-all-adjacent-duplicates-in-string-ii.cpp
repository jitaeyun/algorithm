class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> v;
        string sol;
        for(int i=0; i<s.length(); ++i){
            if(v.empty() || v.back().first!=s[i]) v.push_back({s[i],1});
            else if(++v.back().second==k) v.pop_back();
        }
        for(int i=0; i<v.size(); ++i)
            for(int j=0; j<v[i].second; ++j) 
                sol.push_back(v[i].first);
        return sol;
    }
};