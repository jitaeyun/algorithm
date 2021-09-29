# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        sol, lens, n ,g  = list(), 0, 0, 0
        cur, t = head, None
        while cur:
            lens+=1
            cur=cur.next
        cur = head
        while cur:
            if n == 0:
                n = (lens//k)+1 if lens%k>0 else (lens//k)
                sol.append(cur)
            n-=1
            if n==0:
                cur.next, cur = None, cur.next
                if lens%k>0:
                    lens-=1
                g+=1
            else:
                cur=cur.next
        while g<k:
            g+=1
            sol.append(None)
        return sol
            