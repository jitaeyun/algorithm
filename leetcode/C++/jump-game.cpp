class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i=0,m_idx=0; i<nums.size(); ++i){
            if(m_idx<i) return false;
            m_idx = max(m_idx, i+nums[i]);
        }
        return true;
    }
};