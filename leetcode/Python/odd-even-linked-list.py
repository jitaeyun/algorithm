# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        odd, even, es, cur, i = None, None, None, head, 0
        while cur:
            if i%2:
                if not even:
                    es=even=cur
                else:
                    even.next=cur
                    even=even.next
            else:
                if not odd:
                    odd=cur
                else:
                    odd.next=cur
                    odd=odd.next
            cur=cur.next
            i+=1
        if odd:
            odd.next=es
        if even:
            even.next=None
        return head