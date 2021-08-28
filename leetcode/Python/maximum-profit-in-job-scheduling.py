class Solution:
    def binarySearch(self, v, dp, e):
        l, r, m = 0, e-1, 0
        while l<=r:
            m=(l+r)//2
            if v[m][1]<=v[e][0]:
                l = m+1
            else:
                r = m-1
        return dp[l-1] if l>=1 else 0
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        dp, v = [0]*len(profit), [(startTime[i],endTime[i],profit[i]) for i in range(len(profit))]
        v.sort(key=lambda x : x[1])
        for i in range(len(v)):
            if i>0:
                dp[i]=dp[i-1]
            dp[i]=max(dp[i],self.binarySearch(v,dp,i)+v[i][2])
        return dp[-1]