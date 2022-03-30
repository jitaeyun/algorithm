class Solution {
public:
    int rowSearch(vector<vector<int>>& matrix, int &target){
        int l=0, r=(int)matrix.size()-1,m=0, sol=0;
        while(l<=r){
            m=(l+r)/2;
            if(matrix[m][0]>target) r=m-1;
            else {
                sol=m;
                l=m+1;
            }
        }
        return sol;
    }
    bool colSearch(vector<int> &row, int& target){
        int l=0, r=(int)row.size()-1, m=0;
        while(l<=r){
            m=(l+r)/2;
            if(row[m]>target) r=m-1;
            else if(row[m]<target) l=m+1;
            else return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = rowSearch(matrix, target);
        return colSearch(matrix[r], target);
    }
};