class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int sz;
    KthLargest(int k, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=(int)nums.size()-1,j=0; i>=0&&j<k; --i,++j) pq.push(nums[i]);
        sz=k;
    }
    
    int add(int val) {
        pq.push(val); 
        if(pq.size()>sz) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */