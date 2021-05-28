class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        visit, sol, t, idx = [0 for i in range(10001)], 0, 0, 0
        for i, v in enumerate(nums):
            if visit[v] > 0:
                while idx < i:
                    t-=nums[idx]
                    visit[nums[idx]]-=1
                    if v == nums[idx]:
                        idx+=1
                        break
                    idx+=1
            visit[v]+=1
            t+=v
            sol=max(sol,t)
        return sol