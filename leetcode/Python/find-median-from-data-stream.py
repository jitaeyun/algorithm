class MedianFinder:

    def __init__(self):
        self.minHeap = []
        self.maxHeap = []
        self.sz = 0

    def addNum(self, num: int) -> None:
        if self.sz % 2 == 0:
            heapq.heappush(self.maxHeap,(-num,num))
        else:
            heapq.heappush(self.minHeap,(num,num))
        self.sz+=1
        if self.sz > 1 and self.maxHeap[0][1] > self.minHeap[0][1]:
            a, b = heapq.heappop(self.maxHeap), heapq.heappop(self.minHeap)
            heapq.heappush(self.maxHeap,(-b[1],b[1]))
            heapq.heappush(self.minHeap,(a[1],a[1]))
    def findMedian(self) -> float:
        if self.sz % 2 == 1:
            return self.maxHeap[0][1]
        return (self.maxHeap[0][1]+self.minHeap[0][1])/2
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()