# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        v, cur, = list(), head
        while cur:
            v.append(cur)
            cur = cur.next
        cur = head
        for i in range(len(v)):
            if i&1 == 1:
                cur.next = v[len(v)-1-i//2]
            else:
                cur.next = v[i//2]
            cur = cur.next
            cur.next = None
        