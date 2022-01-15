class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        dq, idx, m = collections.deque(), 0, 0
        dq.append(0)
        while dq:
            idx = dq.popleft()
            for i in range(max(idx+minJump,m+1),min(idx+maxJump+1,len(s))):
                if s[i]=='0':
                    dq.append(i)
                    if i+1==len(s):
                        return True
            m = min(idx+maxJump,len(s)-1)
        return False