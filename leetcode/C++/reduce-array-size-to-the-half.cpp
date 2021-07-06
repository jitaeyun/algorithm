class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int sz = arr.size(), t=arr.size(), sol = 0;
        vector<int> v;
        unordered_map<int,int> um;
        for(int &t:arr) ++um[t];
        for(const pair<int,int> &p : um) v.push_back(p.second);
        sort(v.begin(),v.end(), [](int &a, int &b) {return a>b;});
        for(int i=0; i<v.size(); ++i){
            t-=v[i]; ++sol;
            if(sz/2>=t) break;
        }
        return sol;
    }
};