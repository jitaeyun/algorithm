# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        cur, prev = head, None
        while cur:
            if cur.val == val:
                if prev is None:
                    head = head.next
                else:
                    prev.next=cur.next
            else:
                prev=cur
            cur=cur.next
        return head