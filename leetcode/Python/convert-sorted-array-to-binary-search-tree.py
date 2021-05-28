# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        def _dfs(s, e):
            if s>e:
                return None
            m=(s+e)//2
            t=TreeNode(nums[m])
            t.left=_dfs(s,m-1)
            t.right=_dfs(m+1,e)
            return t
        return _dfs(0,len(nums)-1)