class Solution {
public:
    int ccw(vector<int> &a, vector<int> &b, vector<int> &c){
        return (b[0]-a[0])*(c[1]-a[1]) - (b[1]-a[1])*(c[0]-a[0]);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> sol;
        int idx=0,val;
        for(int i=1; i<trees.size(); ++i){
            if(trees[idx][1]>trees[i][1]) idx=i;
            else if(trees[idx][1]==trees[i][1] && trees[idx][0]>trees[i][0]) idx=i;
        }
        val=trees[idx][0]; trees[idx][0]=trees[0][0]; trees[0][0]=val;
        val=trees[idx][1]; trees[idx][1]=trees[0][1]; trees[0][1]=val;
        sort(trees.begin()+1, trees.end(),[&](vector<int> &a, vector<int> &b){
            int t=(a[0]-trees[0][0])*(b[1]-trees[0][1])-(a[1]-trees[0][1])*(b[0]-trees[0][0]);
            if(t==0) return (a[0]-trees[0][0])*(a[0]-trees[0][0])+(a[1]-trees[0][1])*(a[1]-trees[0][1]) < (b[0]-trees[0][0])*(b[0]-trees[0][0])+(b[1]-trees[0][1])*(b[1]-trees[0][1]);
            return t>0;
        });
        for(vector<int> &t : trees){
            while(sol.size()>=2 && ccw(sol[sol.size()-2],sol.back(),t)<0) sol.pop_back();
            sol.push_back(t);
        }
        for(int i=0,j=0; i<trees.size()&&j<sol.size(); ++i){
            if(trees[i]==sol[j]) ++j;
            else if(ccw(trees[0],trees[1],trees[i])==0 || ccw(trees[0],trees.back(),trees[i])==0) {
                sol.push_back(trees[i]);
            }
        }
        return sol;
    }
};