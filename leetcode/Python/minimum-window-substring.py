class Solution:
    def minWindow(self, s: str, t: str) -> str:
        dq, need, cur, st, end, n = collections.deque(), defaultdict(int), defaultdict(int), 0, -1, 0
        for i, v in enumerate(t):
            need[v]+=1
        for i, v in enumerate(s):
            if v in need:
                cur[v]+=1
                if cur[v] <= need[v]:
                    n+=1
                dq.append(i)
                while dq and cur[s[dq[0]]] > need[s[dq[0]]]:
                    cur[s[dq.popleft()]]-=1
                if n==len(t) and (end==-1 or i-dq[0]<end-st):
                    st, end = dq[0], i
        return s[st:end+1] if end>=0 else ''