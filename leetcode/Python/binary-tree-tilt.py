# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        sol = [0]
        def traverse(node):
            if node is None:
                return 0
            l, r = traverse(node.left), traverse(node.right)
            sol[0] += (l-r) if l>r else r-l
            return l + r + node.val
        traverse(root)
        return sol[0]