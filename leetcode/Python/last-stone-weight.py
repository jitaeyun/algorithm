class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        pq = list()
        for s in stones:
            heapq.heappush(pq, -s)
        while len(pq) > 1:
            a = -heapq.heappop(pq)
            b = -heapq.heappop(pq)
            if a>b:
                heapq.heappush(pq, b-a)
        return 0 if len(pq)==0 else -pq[0]