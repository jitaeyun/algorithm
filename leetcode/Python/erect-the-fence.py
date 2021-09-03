class Solution:
    def ccw(self, a, b, c):
        return (b[0]-a[0])*(c[1]-a[1]) - (b[1]-a[1])*(c[0]-a[0])
    def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
        sol, mins = [], min(trees)
        trees.pop(trees.index(mins))
        trees.sort(key = lambda x : (atan2(x[1]-mins[1], x[0]-mins[0]), (x[1]-mins[1])**2 + (x[0]-mins[0])**2))
        sol.append(mins)
        for t in trees:
            while len(sol)>=2 and self.ccw(sol[-2],sol[-1],t)<0:
                sol.pop()
            sol.append(t)
        i,j=0,1
        while i<len(trees) and j<len(sol):
            if trees[i]==sol[j]:
                j+=1
            elif self.ccw(mins,trees[0],trees[i])==0 or self.ccw(mins,trees[-1],trees[i])==0:
                sol.append(trees[i])
            i+=1
        return sol
        