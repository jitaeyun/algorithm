class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        y, x, d = 0, 0, 0
        dy, dx = [1,0,-1,0], [0,-1,0,1]
        for i in range(4):
            for ins in instructions:
                if ins == 'L':
                    d = (d+1)%4
                elif ins == 'R':
                    d = (d+3)%4
                else:
                    y, x = y+dy[d], x+dx[d]
            if y == 0 and x == 0 and d == 0:
                return True
        return False