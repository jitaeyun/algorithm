class MyCalendarTwo:

    def __init__(self):
        self.t = []

    def book(self, start: int, end: int) -> bool:
        idx, mn, mx, l = len(self.t), start, end, []
        for i, (s,e) in enumerate(self.t):
            mn, mx = max(start,s), min(end,e)
            if mn < mx:
                for k in l:
                    if max(mn,k[0]) < min(mx,k[1]):
                        return False
                l.append((mn,mx))
            if idx==len(self.t) and start<s:
                idx=i
        self.t.insert(idx,(start,end))
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)