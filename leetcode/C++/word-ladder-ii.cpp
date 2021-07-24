class Solution {
public:
    vector<vector<int>> paths;
    vector<vector<string>> sol;
    bool transform(string &a, string &b){
        int c=0;
        if(a.length() != b.length()) return false;
        for(int i=0; i<a.length()&&c<2; ++i){
            if(a[i]!=b[i]) ++c;
        }
        return (c==1)? true : false;
    }
    void makePaths(vector<string>& wordList){
        paths=vector<vector<int>>(wordList.size());
        for(int i=0; i<wordList.size(); ++i){
            for(int j=i+1; j<wordList.size(); ++j){
                if(transform(wordList[i],wordList[j])){
                    paths[i].push_back(j);
                    paths[j].push_back(i);
                }
            }
        }
    }
    void findPaths(string &beginWord, string &endWord, vector<string>& wordList){
        queue<int> q;
        vector<int> visit(wordList.size(),0);
        vector<vector<int>> sol_paths;
        int idx=0, endIdx=-1, s=0, e=0;
        for(int i=0; i<wordList.size(); ++i){
            if(transform(wordList[i], beginWord)){
                q.push(i);
                visit[i]=1;
            }
            if(endWord==wordList[i]) endIdx=i;
        }
        if(endIdx==-1) return;
        while(!q.empty()){
            idx=q.front(); q.pop();
            if(visit[endIdx]>0 && visit[endIdx]<visit[idx]) break;
            for(int &next_idx : paths[idx]){
                if(visit[next_idx]) continue;
                q.push(next_idx);
                visit[next_idx]=visit[idx]+1;
            }
        }
        if(visit[endIdx]==0) return;
        sol_paths.push_back({endIdx});
        while(visit[sol_paths.back().back()]>1){
            e=sol_paths.size();
            for(int i=s; i<e; ++i){
                idx = sol_paths[i].back();
                for(int &next_idx : paths[idx]){
                    if(visit[next_idx]+1==visit[idx]){
                        sol_paths.push_back(sol_paths[i]);
                        sol_paths.back().push_back(next_idx);
                    }
                }
            }
            s=e;
        }
        for(int i=s; i<sol_paths.size(); ++i){
            vector<string> t;
            t.push_back(beginWord);
            for(int j=sol_paths[i].size()-1; j>=0; --j){
                t.push_back(wordList[sol_paths[i][j]]);
            }
            sol.push_back(t);
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        makePaths(wordList);
        findPaths(beginWord, endWord, wordList);
        return sol;
    }
};