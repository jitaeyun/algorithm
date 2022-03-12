"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        v, cur, um, idx = list(), head, dict(), 0
        while cur:
            um[cur], t = idx, Node(cur.val)
            if len(v) > 0:
                v[-1].next = t
            v.append(t)
            cur, idx = cur.next, idx+1
        cur, idx = head, 0
        while cur:
            if cur.random is not None:
                v[idx].random = v[um[cur.random]]
            cur, idx = cur.next, idx + 1
        return v[0] if len(v)>0 else None