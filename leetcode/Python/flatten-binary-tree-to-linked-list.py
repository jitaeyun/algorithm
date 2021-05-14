# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.cur = None
    def flatten(self, root: TreeNode) -> None:
        if root:
            root.left, root.right = root.right, root.left
            self.cur=root
            self.flatten(root.right)
            self.cur.right, root.left = root.left, None
            self.flatten(self.cur.right)
