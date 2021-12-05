# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        um = [dict(), dict()]
        def traverse(node, visit, num):
            if node is None:
                return 0
            r = um[visit].get(num, None)
            if r is not None:
                return r
            if visit==1:
                return node.val + traverse(node.left,0,2*num) + traverse(node.right,0,2*num+1)
            a, b= traverse(node.left, 1, 2*num), traverse(node.left, 0, 2*num)
            c, d = traverse(node.right, 1, 2*num+1), traverse(node.right, 0, 2*num+1)
            r=um[visit][num]=max(a,b)+max(c,d)
            return r
        return max(traverse(root,1,1), traverse(root,0,1))