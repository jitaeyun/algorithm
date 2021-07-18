# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverse(self, root, k):
        cur, prev = root.next, root.next
        for i in range(k):
            if i==0:
                cur=cur.next
            else:
                prev.next, cur.next = cur.next, root.next
                root.next, cur = cur, prev.next
        return prev
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        sz = 0
        if k<=1:
            return head
        root = ListNode(0,head)
        cur, c = root, head
        while c!=None:
            sz, c = sz+1, c.next
        for i in range(sz//k):
            cur = self.reverse(cur,k)
        return root.next