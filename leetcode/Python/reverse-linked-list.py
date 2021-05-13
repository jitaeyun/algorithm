# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        p,t = None, None
        while head:
            t, head.next = head.next, p
            head, p = t, head
        return p