class FreqStack:
    def __init__(self):
        self.um = defaultdict(list)
        self.pq = list()
        self.idx = 0

    def push(self, val: int) -> None:
        self.idx += 1
        self.um[val].append(self.idx)
        heapq.heappush(self.pq, [-len(self.um[val]), -self.idx, val])
        

    def pop(self) -> int:
        if len(self.pq) == 0:
            return -1
        v = heapq.heappop(self.pq)
        self.um[v[2]].pop()
        return v[2]


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()