# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        dq, sol, t = collections.deque(), 0, None
        dq.append(root)
        while dq:
            t=dq.pop()
            if t.left:
                dq.append(t.left)
            if t.right:
                dq.append(t.right)
            if low<=t.val<=high:
                sol+=t.val
        return sol