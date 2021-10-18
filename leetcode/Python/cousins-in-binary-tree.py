# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        ary = [-1, -1, -1, -1]
        def traverse(node, p , d):
            if node is None:
                return
            elif node.val == x:
                ary[0], ary[1] = p, d
            elif node.val == y:
                ary[2], ary[3] = p, d
            traverse(node.left, node.val, d+1)
            traverse(node.right, node.val, d+1)
        traverse(root, -1, 0)
        if ary[1]==ary[3] and ary[0]!=ary[2]:
            return True
        return False
            