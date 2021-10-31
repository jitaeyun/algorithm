"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        cur, st = head, list()
        while cur:
            if cur.child:
                if cur.next:
                    st.append(cur.next)
                cur.next, cur.child.prev, cur.child = cur.child, cur, None
            elif cur.next is None and st:
                cur.next = st.pop()
                cur.next.prev = cur
            cur = cur.next
        return head
