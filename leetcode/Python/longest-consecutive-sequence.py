class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        us, sol, n , s, t, i = set(nums), 0, 0, 0, 0, 0
        if not nums:
            return 0
        while i<len(nums):
            if s==0:
                t = nums[i]
            if t in us:
                us.remove(t)
                if s==0:
                    n, s, t = 1, 1, t-1
                elif s==1:
                    n,t = n+1,t-1
                elif s==2:
                    n,t = n+1,t+1
                sol=max(sol,n)
            else:
                if s>0:
                    s=(s+1)%3
                    if s==2:
                        t=nums[i]+1
                if s==0:
                    i+=1
        return sol
                    
                
