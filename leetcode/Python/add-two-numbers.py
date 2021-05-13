# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        h, p, c = l1, None, 0
        while l1 and l2:
            l1.val+=l2.val+c
            c=l1.val//10
            l1.val=l1.val%10
            p, l1, l2 = l1, l1.next, l2.next
        if l2:
            p.next=l2
            l1=l2
        while l1:
            if c==0:
                break
            l1.val+=c
            c=l1.val//10
            l1.val=l1.val%10
            p, l1 = l1, l1.next
        if c>0:
            p.next=ListNode(val=c)
        return h
        