class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        us, n, s, dq,t,p = set(deadends), 0, ['0','0','0','0'], collections.deque(),0,''
        if '0000' in us:
            return -1
        if '0000' == target:
            return 0
        us.add('0000')
        dq.append((s,0))
        while dq:
            s, n = dq.popleft()
            for i in range(4):
                t=int(s[i])
                s[i]=str((t+1)%10)
                p=''.join(s)
                if p not in us:
                    dq.append((s[:],n+1))
                    us.add(p)
                    if p==target:
                        return n+1 
                s[i]=str((t+9)%10)
                p=''.join(s)
                if p not in us:
                    dq.append((s[:],n+1))
                    us.add(p)
                    if p==target:
                        return n+1
                s[i]=str(t)
        return -1