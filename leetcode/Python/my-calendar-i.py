class MyCalendar:

    def __init__(self):
        self.v = []

    def book(self, start: int, end: int) -> bool:
        idx = len(self.v)
        for i, (s,e) in enumerate(self.v):
            if max(s,start) < min(e,end):
                return False
            if start<s:
                idx=i
                break
        self.v.insert(idx,(start,end))
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)