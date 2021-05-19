# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        pq, sol, cur = [], ListNode(), None
        for i,v in enumerate(lists):
            if v:
                heapq.heappush(pq,(v.val,i))
        cur=sol
        while pq:
            _,i = heapq.heappop(pq)
            cur.next=lists[i]
            cur, lists[i] =cur.next, lists[i].next
            if lists[i]:
                heapq.heappush(pq,(lists[i].val, i))
        return sol.next