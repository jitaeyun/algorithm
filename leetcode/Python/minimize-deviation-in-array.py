class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        sol, mx, mn, pq = 1000000001, 0, 1000000001, list()
        for i in range(len(nums)):
            if nums[i]&1 > 0:
                nums[i]*=2;
            mn = min(mn, nums[i])
            heapq.heappush(pq, (-nums[i], nums[i]))
        while len(pq) > 0:
            _, mx = heapq.heappop(pq) 
            sol = min(sol, mx-mn)
            if mx&1 > 0:
                break
            mx//=2; mn=min(mn, mx); heapq.heappush(pq, (-mx, mx))
        return sol