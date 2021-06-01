# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeList(self, l: ListNode, r:ListNode) -> ListNode:
        if l and r:
            if l.val > r.val:
                l, r = r, l
            l.next = self.mergeList(l.next, r)
        return l if l else r
    def sortList(self, head: ListNode) -> ListNode:
        s, f, t = head, head, None
        if not head or not head.next:
            return head
        while f.next and f.next.next:
            f, s = f.next.next, s.next
        t, s.next= s.next, None
        l = self.sortList(head)
        r = self.sortList(t)
        return self.mergeList(l,r)