# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        sol, cur, st = 0, list(), list()
        st.append([root, root.val, root.val])
        while st:
            cur = st.pop()
            cur[1], cur[2] = min(cur[1], cur[0].val), max(cur[2], cur[0].val)
            sol = max(sol, cur[2]-cur[1])
            if cur[0].left:
                st.append([cur[0].left, cur[1], cur[2]])
            if cur[0].right:
                st.append([cur[0].right, cur[1], cur[2]])
        return sol
                