class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> sol;
        unordered_map<string,vector<string>> um;
        string dir,meta,t;
        int p;
        for(string &path : paths){
            dir=path.substr(0,(p=path.find(" ")));
            t=path.substr(p);
            while((p=t.find(" "))>=0){
                meta=t.substr(1,(p=t.find(")")));
                t=t.substr(p+1);
                um[meta.substr((p=meta.find("(")))].push_back(dir+'/'+meta.substr(0,p));
            }
        }
        for(const pair<string, vector<string>> &p : um)
            if(p.second.size()>1) sol.push_back(p.second);
        return sol;
    }
};