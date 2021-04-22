class Solution:
    def leastBricks(self, wall: List[List[int]]):
        sol = 0
        um = collections.defaultdict(int)
        for i, row in enumerate(wall):
            l = 0
            for j in range(len(row)-1):
                l += row[j]
                um[l]+=1
                sol = max(sol,um[l])
        return len(wall)-sol