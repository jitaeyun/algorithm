class Solution {
public:
    string frequencySort(string s) {
        string sol;
        vector<pair<char,int>> v(52, {'1', 0});
        for(int i=0,idx=0; i<s.length(); ++i){
            idx = (s[i]>='a'&&s[i]<='z')? s[i]-'a' : s[i]-'A'+26;
            v[idx].first=s[i]; v[idx].second+=1;
        }
        sort(v.begin(), v.end(), [](pair<char,int> &a, pair<char,int> &b){
            return (a.second==b.second)? a.first<b.first : a.second>b.second;
        });
        for(int i=0; i<52&&v[i].second>0; ++i)
            for(int j=0; j<v[i].second; ++j) 
                sol.push_back(v[i].first); 
        return sol;
        
    }
};