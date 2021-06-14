class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int sol=0;
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int> &a, vector<int> &b){return a[1]>b[1];});
        for(vector<int> &v : boxTypes){
            if(truckSize>=v[0]){
                truckSize-=v[0];
                sol+=v[1]*v[0];
            }
            else {
                sol+=(v[1])*truckSize;
                break;
            }
        }
        return sol;
    }
};