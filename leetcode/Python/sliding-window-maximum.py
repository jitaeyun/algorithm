class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq, sol = collections.deque(), []
        for i, v in enumerate(nums):
            while dq and nums[dq[-1]]<=v:
                dq.pop()
            if dq and i-dq[0]+1>k:
                dq.popleft()
            dq.append(i)
            if i>=k-1:
                sol.append(nums[dq[0]])
        return sol