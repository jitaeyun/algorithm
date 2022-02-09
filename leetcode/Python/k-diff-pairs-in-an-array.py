class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        um, t, sol, v = defaultdict(int), 0, 0, list()
        for n in nums:
            um[n] += 1
            if um[n] == 1:
                v.append(n)
        for n in v:
            t = um[n-k]
            if n == n-k:
                sol += 1 if t>1 else 0
            elif t > 0:
                sol += 1
        return sol