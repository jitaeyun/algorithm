class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> visit(nums.size(),0);
        queue<int> q; q.push(0);
        if(nums.size()==1) return 0;
        for(int i=0,t; i<nums.size(); ++i){
            t=q.front(); q.pop();
            for(int j=1; j<=nums[t]; ++j) {
                if(j+t+1>=nums.size()) return visit[t] + 1;
                else if(visit[j+t]==0) {
                    q.push(j+t);
                    visit[j+t]=visit[t]+1;
                }
            }
        }
        return 0;
    }
};