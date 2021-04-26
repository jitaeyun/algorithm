from queue import PriorityQueue
class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        que = PriorityQueue()
        cur,t = heights[0],0
        for i in range(1,len(heights)):
            t = heights[i]-cur
            if t > 0:
                que.put(-t)
                bricks-=t
                while bricks<0 and ladders>0:
                    bricks-=que.get()
                    ladders-=1
                if bricks < 0:
                    return i-1
            cur = heights[i]
        return len(heights)-1