class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        sol, mn, mx = 0, min(nums), max(nums)
        mnm, mxm = [mx+1 for i in range(len(nums))], [mn for i in range(len(nums))]
        if mn==mx:
            return sol
        for n in nums:
            idx = int(((len(nums)-1)*(n-mn))/(mx-mn))
            mnm[idx], mxm[idx] = min(mnm[idx],n), max(mxm[idx],n)
        prev=mxm[0]
        for i in range(0,len(mnm)):
            if mnm[i]==mx+1:
                continue
            sol=max(sol,mnm[i]-prev)
            prev=mxm[i]
        return sol