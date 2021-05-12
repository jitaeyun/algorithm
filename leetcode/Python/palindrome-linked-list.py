# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        s, f, r, t = head, head, head, None
        while f and f.next:
            f, t = f.next.next, s.next
            if r:
                s.next, r = r, s
            else:
                r, r.next = s, None
            s=t
        if f:
            s=s.next
        while s and r:
            if s.val != r.val:
                return False
            s, r = s.next, r.next
        return True