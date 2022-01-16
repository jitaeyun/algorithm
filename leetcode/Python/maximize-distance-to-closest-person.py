class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        sol, last_idx = 0, -1
        for i in range(len(seats)):
            if seats[i] == 0:
                continue
            elif last_idx == -1:
                sol = i
            else:
                sol = max(sol, (i-last_idx)//2)
            last_idx = i
        return max(sol, len(seats)-1-last_idx)