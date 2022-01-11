# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        sol, dq , cur, val = 0, collections.deque(), None, 0
        dq.append([root, 0])
        while dq:
            cur = dq.popleft()
            val = (cur[1]<<1) + cur[0].val
            if cur[0].left is None and cur[0].right is None:
                sol += val
            if cur[0].left:
                dq.append([cur[0].left, val])
            if cur[0].right:
                dq.append([cur[0].right, val])
        return sol