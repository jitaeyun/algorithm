class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        dp = [1 for i in range(len(arr))]
        def _traverse(idx):
            sol = 1
            for i in range(idx+1, min(idx+d+1,len(arr))):
                if arr[idx] > arr[i]:
                    sol=max(sol,dp[i]+1)
                else:
                    break
            for i in range(idx-1, max(idx-d-1,-1),-1):
                if arr[idx] > arr[i]:
                    sol=max(sol,dp[i]+1)
                else:
                    break
            dp[idx]=sol
            return sol
        sol = 0
        for _, i in sorted([(arr[i],i) for i in range(len(arr))]):
            sol=max(sol,_traverse(i))
        return sol