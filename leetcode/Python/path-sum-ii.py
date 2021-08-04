# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
        st, sol = [], []
        def dfs(node, curSum):
            if node is None:
                return
            curSum+=node.val
            st.append(node.val)
            if node.left is None and node.right is None and curSum == targetSum:
                sol.append(st[:])
            dfs(node.left, curSum)
            dfs(node.right, curSum)
            st.pop()
        dfs(root, 0)
        return sol
            