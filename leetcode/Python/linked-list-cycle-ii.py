# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        c, f = head, head
        while f and f.next:
            c, f = c.next, f.next.next
            if c == f:
                break
        if f is None or f.next is None:
            return None
        c= head
        while c!=f:
            c, f = c.next, f.next
        return c