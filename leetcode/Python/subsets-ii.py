class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        sol, new_sol = list(), list() 
        def dfs(visit, pos):
            if pos == len(nums):
                l = []
                for i in range(len(nums)):
                    if visit&(1<<i) > 0:
                        l.append(nums[i])
                sol.append(l)
                return
            dfs(visit, pos+1)
            dfs(visit|(1<<pos), pos+1)
        nums.sort()
        dfs(0,0)
        sol.sort()
        for i in sol:
            if not new_sol:
                new_sol.append(i)
            elif new_sol[-1] != i:
                new_sol.append(i)
        return new_sol