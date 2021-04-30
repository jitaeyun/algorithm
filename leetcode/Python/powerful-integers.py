import math
class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        ly = int(math.floor(math.log(bound) / math.log(y)))+1 if y != 1 else 1
        lx = int(math.floor(math.log(bound) / math.log(x)))+1 if x != 1 else 1
        m = [0 for i in range(bound+1)]
        sol = []
        px, py, n = 1,1,0
        for i in range(ly):
            px = 1
            for j in range(lx):
                n = px+py
                if n <=bound and m[n] == 0:
                    m[n]=1
                    sol.append(n)
                px*=x
            py*=y
        return sol