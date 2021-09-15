class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int sol=1, case_one = 1, case_two = 1;
        for(int i=1; i<arr.size(); ++i){
            if(arr[i-1]==arr[i]) case_one=case_two=1;
            else if(i%2==0){
                if(arr[i-1]>arr[i]) {++case_one; case_two=1;}
                else {++case_two; case_one=1;}
            }
            else {
                if(arr[i-1]>arr[i]) {++case_two; case_one=1;}
                else {++case_one; case_two=1;}
            }
            sol=max(sol,case_one);
            sol=max(sol,case_two);
        }
        return sol;
    }
};