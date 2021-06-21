class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> sol;
        for(int i=1; i<=numRows; ++i){
            vector<int> v;
            for(int j=0; j<i; ++j){
                if(j==0 || j+1==i) v.push_back(1);
                else if(i) v.push_back(sol.back().at(j-1)+sol.back().at(j));
            }
            sol.push_back(v);
        }
        return sol;
    }
};