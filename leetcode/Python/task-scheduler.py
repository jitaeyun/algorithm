class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        v, t, mx, idx = [0 for i in range(26)], 0, 0, 0
        for c in tasks:
            idx=ord(c)-ord('A')
            v[idx]+=1
            mx=max(mx,v[idx])
        for i in range(26):
            if mx==v[i]:
                t+=1
        return max(t+(mx-1)*(n+1),len(tasks))