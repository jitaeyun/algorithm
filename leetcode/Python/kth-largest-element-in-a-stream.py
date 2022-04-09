class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.pq = list()
        self.sz = k
        nums.sort()
        j = 0
        for i in range(len(nums)-1, -1, -1):
            heapq.heappush(self.pq, nums[i])
            if j + 1 == k:
                break
            j+=1

    def add(self, val: int) -> int:
        heapq.heappush(self.pq, val)
        if len(self.pq) > self.sz:
            heapq.heappop(self.pq)
        return self.pq[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)