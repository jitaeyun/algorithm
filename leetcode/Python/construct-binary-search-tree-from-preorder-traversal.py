# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        def _traverse(lower, upper, cur):
            if idx[0]==len(preorder):
                return
            if lower<preorder[idx[0]]<upper and preorder[idx[0]]<cur.val:
                cur.left = TreeNode(preorder[idx[0]])
                idx[0]+=1
                _traverse(lower, cur.val, cur.left)
            if idx[0]<len(preorder) and lower<preorder[idx[0]]<upper and preorder[idx[0]]>cur.val:
                cur.right = TreeNode(preorder[idx[0]])
                idx[0]+=1
                _traverse(cur.val, upper, cur.right)
        sol, idx = TreeNode(preorder[0]), [1]
        _traverse(0,10000,sol)
        return sol