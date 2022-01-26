# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        def traverse(node, v):
            if node is None:
                return
            traverse(node.left, v)
            v.append(node.val)
            traverse(node.right, v)
        r1, r2, sol = list(), list(), list()
        r1_idx, r2_idx = 0, 0
        traverse(root1, r1)
        traverse(root2, r2)
        while r1_idx<len(r1) and r2_idx<len(r2):
            if r1[r1_idx]<r2[r2_idx]:
                sol.append(r1[r1_idx])
                r1_idx += 1
            else:
                sol.append(r2[r2_idx])
                r2_idx += 1
        while r1_idx < len(r1):
            sol.append(r1[r1_idx])
            r1_idx += 1
        while r2_idx < len(r2):
            sol.append(r2[r2_idx])
            r2_idx += 1
        return sol