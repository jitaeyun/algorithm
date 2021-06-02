# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        sol, cur, p, t = ListNode(val=-5001), head, None, None
        while cur:
            t=sol
            while t:
                if t.val > cur.val:
                    break
                p, t= t, t.next
            p.next, cur = cur, cur.next
            p.next.next=t
        return sol.next