class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        ny, nx, cy, cx , dy, dx = 0, 0, 0, 0, [1,-1,0,0], [0,0,1,-1]
        sol , visit, group = 0, [[0 for i in range(len(grid[0]))] for j in range(len(grid))], [0]
        def goVisit(y, x):
            group_idx = len(group)
            dq = collections.deque()
            dq.append([y,x])
            group.append(1)
            visit[y][x]=group_idx
            while dq:
                cy, cx = dq.popleft()
                for i in range(4):
                    ny, nx = cy+dy[i], cx+dx[i]
                    if ny<0 or ny>=len(grid) or nx<0 or nx>=len(grid[0]):
                        continue
                    if grid[ny][nx]==0 or visit[ny][nx]:
                        continue
                    dq.append([ny,nx])
                    visit[ny][nx]=group_idx
                    group[group_idx]+=1
        def changeOne(y, x):
            sol = 1
            groupList = set()
            for i in range(4):
                ny, nx = y+dy[i], x+dx[i]
                if ny<0 or ny>=len(grid) or nx<0 or nx>=len(grid[0]):
                    continue
                groupList.add(visit[ny][nx])
            for group_key in groupList:
                sol+=group[group_key]
            return sol
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] > 0 and visit[i][j]==0:
                    goVisit(i,j)
                    sol=max(sol,group[-1])
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    sol=max(sol,changeOne(i,j))
        return sol