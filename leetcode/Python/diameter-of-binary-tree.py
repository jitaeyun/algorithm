# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def traverse(cur):
            if cur is None:
                return 0
            l = traverse(cur.left)
            r = traverse(cur.right)
            sol[0] = max(sol[0], l+r)
            return max(l, r) + 1
        sol = [0]
        traverse(root)
        return sol[0]