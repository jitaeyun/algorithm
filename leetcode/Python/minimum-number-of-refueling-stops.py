class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        visit, pq = [0 for i in range(len(stations))], [(0,-startFuel,-1,0,startFuel)]
        info,f = None,0
        while pq:
            info = heapq.heappop(pq)
            if info[3]+info[4] >= target:
                return info[0]
            if info[2]>=0 and visit[info[2]]>info[3]+info[4]:
                continue
            for i in range(info[2]+1,len(stations)):
                if info[3]+info[4]>=stations[i][0]:
                    f = stations[i][1]+info[3]+info[4]
                    if visit[i]<f:
                        visit[i]=f
                        heapq.heappush(pq,(info[0]+1,-f,i,stations[i][0],f-stations[i][0]))
                else:
                    break
        return -1