class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        um, v, sol, t = defaultdict(int), [], 0, len(arr)
        for i in arr:
            um[i]+=1
        for i,val in um.items():
            v.append(val)
        v.sort()
        for i in range(len(v)-1,-1,-1):
            t-=v[i]
            sol+=1
            if len(arr)//2 >= t:
                break
        return sol