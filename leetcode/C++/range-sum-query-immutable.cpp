class NumArray {
public:
    vector<int> v;
    NumArray(vector<int>& nums) {
        for(int &n : nums){
            if(v.empty()) v.push_back(n);
            else v.push_back(v.back()+n);
        }
    }
    
    int sumRange(int left, int right) {
        return (left>0)? v[right]-v[left-1] : v[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */