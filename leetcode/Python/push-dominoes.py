class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        visit, val, sol = [0]*len(dominoes), [0]*len(dominoes), []
        idx, next_idx = 0, 0
        dq = collections.deque()
        for i in range(len(dominoes)):
            if dominoes[i]=='L':
                visit[i], val[i] = 1, -1
                dq.append(i)
            elif dominoes[i]=='R':
                visit[i]=val[i]=1
                dq.append(i)
        while dq:
            idx = dq.popleft()
            next_idx = idx+val[idx]
            if val[idx]==0 or (next_idx<0 or next_idx>=len(dominoes)) or (visit[idx]+1>visit[next_idx]>0):
                continue
            visit[next_idx]=visit[idx]+1
            val[next_idx]+=val[idx]
            dq.append(next_idx)
        for i in val:
            if i==-1:
                sol.append('L')
            elif i==1:
                sol.append('R')
            else:
                sol.append('.')
        return ''.join(sol)