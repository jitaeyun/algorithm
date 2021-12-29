"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        cur, prev, dq, sz = None, None, collections.deque(), 0
        if root is None:
            return root
        dq.append(root)
        while dq:
            sz = len(dq)
            for i in range(sz):
                cur = dq.popleft()
                if cur.left is not None:
                    dq.append(cur.left)
                if cur.right is not None:
                    dq.append(cur.right)
                if i>0:
                    prev.next = cur
                prev = cur
        return root