# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        sol, tail, t, cur, sz, idx = head, head, head, head, 0, 0
        if sol is None:
            return sol
        while cur:
            sz, tail, cur = sz + 1, cur, cur.next
        s_idx = (sz-(k%sz))%sz
        e_idx = (s_idx-1+sz)%sz
        cur = head
        while cur and idx<=max(s_idx, e_idx):
            if idx == s_idx:
                sol = cur
            if idx == e_idx:
                t = cur
            cur, idx = cur.next, idx + 1
        tail.next = head
        t.next = None
        return sol