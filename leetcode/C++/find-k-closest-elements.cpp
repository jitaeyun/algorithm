class Solution {
public:
    int diff(int &val, int &x){return (val<x)? x-val : val-x;}
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx=0, val=1000000, l=0, r=arr.size()-1, a,b, m;
        while(l<=r){
            m=(l+r)/2;
            if(arr[m]<x) l=m+1;
            else if(arr[m]==x) {idx=m; break;}
            else r=m-1;
            if((a=diff(arr[m],x))<val) {idx=m; val=a;}
        }
        l=idx-1; r=idx+1;
        while(--k>0 && l>=0 && r<arr.size()){
            if((a=diff(arr[l],x))<=(b=diff(arr[r],x))) --l;
            else ++r;
        }
        if(k>0){
            if(l>=0) l-=k;
            else r+=k;
        }
        return vector<int>(arr.begin()+l+1, arr.begin()+r);
    }
};