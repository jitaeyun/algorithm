# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        sol, node = 0, head
        while node:
            sol <<= 1
            sol |= node.val
            node = node.next
        return sol