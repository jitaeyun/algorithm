# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur, sz = head, 0
        while cur:
            sz += 1
            cur = cur.next
        cur = head
        for i in range(sz//2):
            cur = cur.next
        return cur