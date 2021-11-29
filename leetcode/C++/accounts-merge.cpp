class Solution {
public:
    vector<int> group;
    int find(int a){
        if(group[a]==0) return a;
        return group[a]=find(group[a]);
    }
    void unions(int a, int b){
        a=find(a); b=find(b);
        if(a==b) return;
        else if(a<b) group[b]=a;
        else group[a]=b;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> sol, t(accounts.size());
        unordered_map<string, int> um;
        unordered_map<string, int>::iterator it;
        string str;
        group.push_back(0);
        for(int i=0; i<accounts.size(); ++i){
            group.push_back(0);
            for(int j=1; j<accounts[i].size(); ++j){
                str = accounts[i][0]+"+"+accounts[i][j];
                if((it=um.find(str))==um.end()) um.insert({str, i+1});
                else unions(i+1, it->second);
            }
        }
        for(int i=0; i<accounts.size(); ++i){
            for(int j=1; j<accounts[i].size(); ++j){
                int &r=um.find(accounts[i][0]+"+"+accounts[i][j])->second;
                if(r==-1) continue;
                t[find(r)-1].push_back(accounts[i][j]);
                r=-1;
            }
        }
        for(int i=0; i<t.size(); ++i){
            if(t[i].empty()) continue;
            sort(t[i].begin(), t[i].end());
            sol.push_back({accounts[i][0]});
            sol.back().insert(sol.back().end(), t[i].begin(), t[i].end());
        }
        return sol;
    }
};