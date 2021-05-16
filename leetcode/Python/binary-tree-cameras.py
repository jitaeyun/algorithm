# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans=0
    def installCamera(self, parent, node):
        if parent:
            parent.val+=1
        if node.left:
            node.left.val+=1
        if node.right:
            node.right.val+=1
        node.val+=1
        self.ans+=1
    def checkCameras(self, parent, node):
        if not node:
            return
        self.checkCameras(node,node.left)
        self.checkCameras(node,node.right)
        if node.left and node.left.val == 0:
            self.installCamera(parent,node)
        if node.right and node.right.val == 0:
            self.installCamera(parent,node)
    def minCameraCover(self, root: TreeNode) -> int:
        self.checkCameras(None,root)
        if root.val == 0:
            self.ans+=1
        return self.ans
        