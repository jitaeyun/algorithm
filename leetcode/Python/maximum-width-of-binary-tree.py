# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        sol, cur, diff, val = 0, 0, 0, 0
        dq = collections.deque([[root, 0]])
        while len(dq) > 0:
            diff = dq[0][1]
            for i in range(len(dq)):
                cur, val = dq.popleft()
                if cur.left:
                    dq.append([cur.left, (val-diff)*2])
                if cur.right:
                    dq.append([cur.right, (val-diff)*2+1])
            sol = max(sol, val-diff+1)
        return sol