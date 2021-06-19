class NumArray {
public:
    vector<int> tree;
    int n;
    int makeTree(vector<int>& nums, int idx, int l, int r){
        if(l>=r) return tree[idx]=nums[l];
        int m = (l+r)/2;
        return tree[idx]=makeTree(nums,idx*2+1,l,m)+makeTree(nums,idx*2+2,m+1,r);
    }
    int updateTree(int &index, int &val, int idx, int l, int r){
        int diff=0, m=(l+r)/2;
        if(l>=r) {
            diff = val - tree[idx];
            tree[idx]+=diff;
            return diff;
        }
        if(index<=m) diff=updateTree(index,val,idx*2+1,l,m);
        else diff=updateTree(index,val,idx*2+2,m+1,r);
        tree[idx]+=diff;
        return diff;
    }
    int query(int &ql, int &qr, int idx, int l, int r){
        if(qr<l || ql>r) return 0;
        if(ql<=l && r<=qr) return tree[idx];
        int m = (l+r)/2;
        return query(ql,qr,idx*2+1,l,m) + query(ql,qr,idx*2+2,m+1,r);
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        tree=vector<int>(n*4,0);
        makeTree(nums,0,0,n-1);
    }
    
    void update(int index, int val) {
        updateTree(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return query(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */