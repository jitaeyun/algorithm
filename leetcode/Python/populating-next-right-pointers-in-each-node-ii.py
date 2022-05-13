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
    def connect(self, root: 'Node') -> 'Node':
        dq = collections.deque()
        sz, cur, prev = 0, None, None
        if root is None:
            return root
        dq.append(root)
        while dq:
            prev = None
            for i in range(len(dq)):
                cur = dq.popleft()
                if cur.left is not None:
                    dq.append(cur.left)
                if cur.right is not None:
                    dq.append(cur.right)
                if prev is not None:
                    prev.next = cur
                prev = cur
        return root