# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        s, p, cur = None, None, head
        for i in range(left):
            s, p, cur = p, cur, cur.next
        for i in range(left, right):
            p.next=cur.next
            if s:
                cur.next, s.next = s.next, cur
            else:
                cur.next, head = head, cur
            cur=p.next
        return head