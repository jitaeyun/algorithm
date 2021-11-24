class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> sol;
        for(int i=0,j=0; i<firstList.size()&&j<secondList.size(); ){
            if(secondList[j][1] < firstList[i][0]) ++j;
            else if(secondList[j][0] > firstList[i][1]) ++i;
            else {
                sol.push_back({max(firstList[i][0], secondList[j][0]),min(firstList[i][1], secondList[j][1])});
                if(firstList[i][1]<secondList[j][1]) ++i;
                else ++j;
            }
        }
        return sol;
    }
};