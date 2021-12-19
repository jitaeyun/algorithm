class Solution:
    def decodeString(self, s: str) -> str:
        ns, ss, n = [1], [''], 0
        for ch in s:
            if ch>='0' and ch<='9':
                n = n*10 + ord(ch)-ord('0')
            elif ch>='a' and ch<='z':
                ss[-1]+=ch
            elif ch=='[':
                ss.append('')
                if n==0:
                    ns.append(1)
                else:
                    ns.append(n)
                n=0
            else:
                t = ''
                for i in range(ns.pop()):
                    t += ss[-1]
                ss.pop()
                ss[-1]+=t
        return ss.pop()