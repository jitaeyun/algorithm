# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        s = [0]
        def traverse(node):
            if node is None:
                return
            traverse(node.right)
            node.val += s[0]
            s[0] = node.val
            traverse(node.left)
        traverse(root)
        return root