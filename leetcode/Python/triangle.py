class Solution:
    def minimumTotal(self, triangle: List[List[int]]):
        cur = [0 for i in range(200)]
        next = [0 for i in range(200)]
        sol = 10000
        for i, row in enumerate(triangle):
            for j, v in enumerate(row):
                if j == 0:
                    next[j]=cur[j]+v
                elif j + 1 == len(row):
                    next[j]=cur[j-1]+v
                else:
                    next[j]=min(cur[j-1],cur[j])+v
            cur=next.copy()
        for i in range(len(triangle)):
            if sol > cur[i]:
                sol = cur[i]
        return sol