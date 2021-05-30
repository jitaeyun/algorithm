# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.idx=0
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def build(s,e):
            if self.idx == len(preorder):
                return None
            j=s
            while j<=e:
                if preorder[self.idx] == inorder[j]:
                    break
                j+=1
            if j == e+1:
                return None
            t=TreeNode(preorder[self.idx])
            self.idx+=1
            if j>0:
                t.left=build(s,j-1)
            if j+1 < len(inorder): 
                t.right=build(j+1,e)
            return t
        return build(0,len(inorder)-1)
            