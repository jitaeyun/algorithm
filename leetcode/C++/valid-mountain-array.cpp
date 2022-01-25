class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int inIdx=0, deIdx=(int)arr.size()-1;
        for(; inIdx+1 < arr.size(); ++inIdx) if(arr[inIdx]>=arr[inIdx+1]) break;
        for(; deIdx >= 1; --deIdx) if(arr[deIdx]>=arr[deIdx-1]) break;
        return (inIdx==deIdx) && (inIdx>0) && (inIdx+1<arr.size());
    }
};