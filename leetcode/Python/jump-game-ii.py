class Solution:
    def jump(self, nums: List[int]) -> int:
        visit = [0 for i in range(len(nums))]
        q, t = [0],0
        if len(nums) == 1:
            return 0
        for i in range(len(nums)):
            t = q.pop(0)
            for j in range(1,nums[t]+1):
                if j+t+1 >= len(nums):
                    return visit[t] + 1
                if visit[j+t] == 0:
                    q.append(j+t)
                    visit[j+t]=visit[t]+1
        return 0
'''
class Solution:
    def jump(self, nums: List[int]) -> int:
        sol, dist, cur = 1, 0, nums[0]
        if len(nums) == 1:
            return 0
        for i in range(len(nums)):
            if i+nums[i] > dist:
                dist = i+nums[i]
            if i == cur:
                cur = dist
                sol += 1
            if cur+1 >= len(nums):
                return sol
        return 0
'''