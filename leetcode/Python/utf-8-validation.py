class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        v, state, bit = [], 0, 0
        def _trans(n):
            s, i= [], 128;
            while i>0:
                if i&n > 0:
                    s.append(1)
                else:
                    s.append(0)
                i>>=1
            v.append(s)
        for d in data:
            _trans(d)
        for d in v:
            for i in range(8):
                if state==0:
                    if d[0]==0:
                        break
                    elif d[i]==1:
                        bit+=1
                    else:
                        if bit<=1 or bit>4:
                            return False
                        state=1
                        bit-=1
                        break
                else:
                    if d[0]==1 and d[1]==0:
                        bit-=1
                    else:
                        return False
                    if bit==0:
                        state=0
                    break
        print(v)
        return bit==0