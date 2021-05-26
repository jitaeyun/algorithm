# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: TreeNode, root2: TreeNode) -> TreeNode:
        def _dfs(r, t):
            if not r or not t:
                return
            r.val+=t.val
            if r.left and t.left:
                _dfs(r.left,t.left)
            elif t.left:
                r.left=t.left
            if r.right and t.right:
                _dfs(r.right,t.right)
            elif t.right:
                r.right=t.right
        _dfs(root1,root2)
        return root1 if root1 else root2