class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> sol, v;
        vector<vector<int>> parent(numCourses), child(numCourses);
        vector<int>::iterator it;
        for(vector<int> &t : prerequisites){
            parent[t[0]].push_back(t[1]);
            child[t[1]].push_back(t[0]);
        }
        for(int i=0; i<numCourses; ++i) if(parent[i].empty()) v.push_back(i);
        while(!v.empty()){
            sol.push_back(v.back()); v.pop_back();
            for(int &t:child[sol.back()]){
                if((it=find(parent[t].begin(), parent[t].end(), sol.back())) != parent[t].end()){
                    *it=parent[t].back();
                    parent[t].pop_back();
                    if(parent[t].empty()) v.push_back(t);
                }
            }
        }
        return sol.size()==numCourses;
    }
};