# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        def getHeight(node):
            l = -1
            while node:
                node, l = node.left, l + 1
            return l
        h, sol = 0, 0
        if (h:=getHeight(root)) == -1:
            return 0
        sol = 1<<h
        for i in range(h, 0, -1):
            if getHeight(root.right)+1 == i:
                sol, root = sol + (1<<i-1), root.right
            else:
                root = root.left
        return sol