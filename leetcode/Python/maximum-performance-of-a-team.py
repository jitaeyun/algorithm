class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        sol, s_sum, e_cur, v, pq = 0, 0, 0, [(efficiency[i], speed[i]) for i in range(n)], []
        v.sort(reverse=True)
        for i, (e,s) in enumerate(v):
            heappush(pq,s)
            e_cur, s_sum = e, s_sum+s
            if i>=k:
                s_sum-=heappop(pq)
            sol=max(sol,s_sum*e_cur)
        return sol%1000000007
        