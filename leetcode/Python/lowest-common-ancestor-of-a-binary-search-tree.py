# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        mn, mx = min(p.val, q.val), max(p.val, q.val)
        while root.val < mn or root.val > mx:
            root = root.left if root.val>mx else root.right
        return root