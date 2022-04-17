# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        v = list()
        def traverse(node):
            if node is None:
                return
            traverse(node.left)
            v.append(node)
            traverse(node.right)
        traverse(root)
        for i in range(len(v)):
            v[i].left=v[i].right=None
            if i>0:
                v[i-1].right = v[i]
        return v[0]