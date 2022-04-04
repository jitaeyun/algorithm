# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        v = list()
        cur = head
        k -= 1
        while cur:
            v.append(cur)
            cur = cur.next
        v[k].val, v[-k-1].val = v[-k-1].val, v[k].val
        return head