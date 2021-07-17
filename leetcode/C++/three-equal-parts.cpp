class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int ones=0, state=0, v[]={-1,-1,-1}, len=0, l,r;
        for(int &t : arr) if(t==1) ++ones;
        if(ones==0) return {0,(int)arr.size()-1};
        else if(ones%3) return {-1,-1};
        for(int i=0,j=0; i<arr.size()&&state<3; ++i) {
            if(arr[i]==1) {
                if(v[state]==-1) v[state]=i;
                if(++j==ones/3) {j=0; ++state;}
            }
        }
        len=arr.size()-v[2];
        if(len>v[1] || len>v[2]-v[1]) return {-1,-1};
        for(int i=0; i<len; ++i){
            if(arr[v[0]+i]!=arr[v[2]+i] || arr[v[1]+i]!=arr[v[2]+i]) return {-1, -1};
            l=v[0]+i; r=v[1]+i+1;
        }
        return {l,r};
    }
};