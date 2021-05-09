class Solution:
    def isPossible(self, target: List[int]) -> bool:
        if len(target) == 1:
            return target[0]==1
        curSum, prevSum, num, n = sum(target), 0, 0, 0
        max_heap = [-i for i in target]
        heapq.heapify(max_heap)
        while max_heap[0]<-1:
            prevSum=-heapq.heappop(max_heap)
            n=(prevSum+max_heap[0])//(curSum-prevSum)
            if n<=0:
                n=1
            num=prevSum-n*(curSum-prevSum)
            if num<1:
                return False
            heapq.heappush(max_heap,-num)
            curSum=curSum-prevSum+num
        return True