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

'''
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        sol = list()
        intervals.sort()
        for interval in intervals:
            if len(sol) == 0 or sol[-1][1] < interval[0]:
                sol.append(interval)
            elif sol[-1][1] < interval[1]:
                sol[-1][1] = interval[1]
        return sol
        
'''