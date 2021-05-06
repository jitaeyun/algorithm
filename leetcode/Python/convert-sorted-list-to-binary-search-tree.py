# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.v = list()
    def traverse(self,l,r):
        if l>r:
            return None
        m = l + (r-l)//2
        return TreeNode(self.v[m],self.traverse(l,m-1),self.traverse(m+1,r))
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        while head is not None:
            self.v.append(head.val)
            head=head.next
        if len(self.v) == 0:
            return None
        return self.traverse(0,len(self.v)-1)