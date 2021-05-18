class MyQueue:

    def __init__(self):
        self.st, self.t=[], []
        
    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.st.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        self.peek()
        return self.t.pop()
        
    def peek(self) -> int:
        """
        Get the front element.
        """
        if not self.t:
            while self.st:
                self.t.append(self.st.pop())
        return self.t[-1]
        
    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return not self.st and not self.t


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()