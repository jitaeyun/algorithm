# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        dq, sol, cur = collections.deque(), 0, None
        dq.append(root)
        while dq:
            cur = dq.popleft()
            if cur is None:
                continue
            if cur.left:
                dq.append(cur.left)
                if cur.left.left is None and cur.left.right is None:
                    sol += cur.left.val
            if cur.right:
                dq.append(cur.right)
        return sol