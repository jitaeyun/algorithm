# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def __init__(self):
        t=None
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        prev=head.next
        self.t, prev.next = prev.next, head
        head.next=self.swapPairs(self.t)
        return prev