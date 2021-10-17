# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        sol, um, curSum = [0], dict(), [0]
        def traverse(node):
            if node is None:
                return
            curSum[0] += node.val
            if curSum[0] == targetSum:
                sol[0]+=1
            sol[0] += um.get(curSum[0]-targetSum, 0)
            um[curSum[0]]=um.get(curSum[0], 0) + 1
            traverse(node.left)
            traverse(node.right)
            um[curSum[0]]-=1
            curSum[0] -= node.val
        traverse(root)
        return sol[0]