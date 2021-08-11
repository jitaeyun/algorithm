class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int t=0;
        unordered_map<int,int> um;
        sort(arr.begin(),arr.end());
        for(int &n : arr) um[n]+=1;
        for(int &n : arr){
            if(--um[n]<0) continue;
            else if(n<0 && n%2) return false;
            t = (n>=0)? 2*n : n/2; 
            if(--um[t]<0) return false;
        }
        return true;
    }
};