# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node, maxVal):
        count=0
        if not node:
            return count
        if node.val>=maxVal:
            count+=1
            maxVal=node.val
        count+=self.dfs(node.left,maxVal)+self.dfs(node.right,maxVal)
        return count
            
    def goodNodes(self, root: TreeNode) -> int:
        return self.dfs(root, -10000)