class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dq = collections.deque()
        

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.dq.append(x)
        for i in range(1,len(self.dq)):
            self.dq.append(self.dq.popleft())
        

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.dq.popleft()

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.dq[0]
        

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not self.dq
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()