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
/*
class Solution {
public:
    int jump(vector<int>& nums) {
        int dist=0,cur=nums[0],sol=1,sz=nums.size();
        if(sz==1) return 0;
        for(int i=0; i<sz&&cur+1<sz; ++i){
            if(dist<i+nums[i]) dist=i+nums[i];
            if(i==cur){
                cur=dist;
                ++sol;
            }
        }
        return sol;
    }
};
*/