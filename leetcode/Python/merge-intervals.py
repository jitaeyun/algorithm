class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        sol = []
        intervals.sort()
        for i in intervals:
            if not sol or sol[-1][1]<i[0]:
                sol.append(i)
            else:
                sol[-1][1]=max(sol[-1][1],i[1])
        return sol