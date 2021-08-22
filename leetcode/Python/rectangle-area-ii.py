class Solution:
    def __init__(self):
        self.MOD = 1000000007
    def rangeArea(self, rectangles, prev_x, cur_x):
        area, my, ys = 0, 0, []
        for r in rectangles:
            if r[0]<=prev_x and r[2]>=cur_x:
                ys.append((r[1],r[3]))
        ys.sort()
        for y in ys:
            my=max(my,y[0])
            if my<y[1]:
                area+=(cur_x-prev_x)*(y[1]-my)
                my=y[1]
        return area
    def rectangleArea(self, rectangles: List[List[int]]) -> int:
        sol, prev_x, x = 0, 0, []
        for r in rectangles:
            x.append(r[0])
            x.append(r[2])
        x.sort()
        prev_x=x[0]
        for i in range(1,len(x)):
            if prev_x == x[i]:
                continue
            sol += self.rangeArea(rectangles, prev_x, x[i])
            prev_x=x[i]
        return sol%self.MOD