class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        def _dfs(idx, sums):
            if visit[0]==fin:
                return True
            elif sums == target:
                sums = idx = 0
            for i in range(idx,len(nums)):
                if (1<<i)&visit[0]>0 or nums[i]+sums > target:
                    continue
                visit[0]|=(1<<i)
                if _dfs(i+1, sums+nums[i]):
                    return True
                visit[0]^=(1<<i)
            return False
        visit, fin, target = [0], (1<<len(nums))-1, sum(nums)
        if target%k>0:
            return False
        target//=k
        return _dfs(0, 0)