# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.sol=0
    def isBalanced(self, root: TreeNode) -> bool:
        def _dfs(n):
            if not n:
                return 0
            a, b = _dfs(n.left)+1, _dfs(n.right)+1
            self.sol=max(self.sol,a-b if a>b else b-a)
            return max(a,b)
        _dfs(root)
        return self.sol<2