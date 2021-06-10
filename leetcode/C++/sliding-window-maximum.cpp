class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> sol;
        for(int i=0; i<nums.size(); ++i){
            while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();
            if(!dq.empty() && i-dq.front()+1>k) dq.pop_front();
            dq.push_back(i);
            if(i>=k-1) sol.push_back(nums[dq.front()]);
        }
        return sol;
    }
};