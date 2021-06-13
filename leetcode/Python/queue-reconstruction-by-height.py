class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        sol = []
        for v in sorted(people,key=lambda x : (-x[0],x[1])):
            sol.insert(v[1],v)
        return sol