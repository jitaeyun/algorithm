class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        sol, dq = 0, collections.deque()
        for i in range(len(nums)):
            if dq and dq[0][0] < i-k:
                dq.popleft()
            sol = nums[i] if not dq else nums[i]+dq[0][1]
            while dq and dq[-1][1] < sol:
                dq.pop()
            dq.append((i,sol))
        return sol