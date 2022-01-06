class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        dp, sz = [0]*1001, 0
        for t in trips:
            dp[t[1]]+=t[0]
            dp[t[2]]-=t[0]
        for i in range(len(dp)):
            sz += dp[i]
            if sz > capacity:
                return False
        return True