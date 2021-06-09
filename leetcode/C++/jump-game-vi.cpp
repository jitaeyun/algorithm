class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int sol=0;
        deque<pair<int,int>> dq;
        for(int i=0,v=0; i<nums.size(); ++i){
            if(!dq.empty() && dq.front().first < i-k) dq.pop_front();
            v = (!dq.empty())? dq.front().second + nums[i] : nums[i];
            while(!dq.empty() && dq.back().second < v) dq.pop_back();
            dq.push_back({i,v});
            sol=v;
        }
        return sol;
    }
};