# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        sol, cur, node, q = 0, 0, None, collections.deque()
        q.append([root,0])
        while q:
            node, cur = q.popleft()
            cur = cur*10 + node.val
            if node.left:
                q.append([node.left,cur])
            if node.right:
                q.append([node.right,cur])
            if node.left is None and node.right is None:
                sol+=cur
        return sol