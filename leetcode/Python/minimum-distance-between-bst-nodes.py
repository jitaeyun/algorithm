# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        dq, sol, v, t = collections.deque(), 100001, [], None
        dq.append(root)
        while dq:
            t=dq.popleft()
            v.append(t.val)
            if t.left:
                dq.append(t.left)
            if t.right:
                dq.append(t.right)
        v.sort()
        for i in range(0, len(v)-1):
            sol=min(sol,v[i+1]-v[i])
        return sol