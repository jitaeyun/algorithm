class MyCircularQueue:

    def __init__(self, k: int):
        self.v, self.sz = [0 for i in range(k+1)],0
        self.l, self.r = 0, 0

    def enQueue(self, value: int) -> bool:
        if self.sz+1 >= len(self.v):
            return False
        self.v[self.r], self.sz, self.r = value, self.sz+1, (self.r+1)%len(self.v)
        return True

    def deQueue(self) -> bool:
        if self.sz == 0:
            return False
        self.sz, self.l = self.sz-1, (self.l+1)%len(self.v)
        return True
        
    def Front(self) -> int:
        return self.v[self.l] if self.sz > 0 else -1

    def Rear(self) -> int:
        return self.v[(self.r+len(self.v)-1)%len(self.v)] if self.sz > 0 else -1
        
    def isEmpty(self) -> bool:
        return self.sz==0

    def isFull(self) -> bool:
        return self.sz+1==len(self.v)


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()