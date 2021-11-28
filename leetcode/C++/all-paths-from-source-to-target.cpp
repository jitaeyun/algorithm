class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> sol;
        queue<vector<int>> q;
        q.push({0});
        while(!q.empty()){
            if(q.front().back()+1 == graph.size()) {sol.push_back(q.front()); q.pop(); continue;}
            for(int &n : graph[q.front().back()]){
                q.front().push_back(n);
                q.push(q.front());
                q.front().pop_back();
            }
            q.pop();
        }
        return sol;
    }
};

/*
DAG은 싸이클이 없는 방향그래프
*/