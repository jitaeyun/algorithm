# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        sol, cur = None, None
        if l1 is None or l2 is None:
            return l1 if l2 is None else l2
        while l1 is not None and l2 is not None:
            if cur is None:
                if l1.val < l2.val:
                    cur, l1 = l1, l1.next
                else:
                    cur, l2 = l2, l2.next
                sol=cur
            else:
                if l1.val < l2.val:
                    cur.next, l1 = l1, l1.next
                else:
                    cur.next, l2 = l2, l2.next
                cur=cur.next
        cur.next = l1 if l2 is None else l2
        return sol