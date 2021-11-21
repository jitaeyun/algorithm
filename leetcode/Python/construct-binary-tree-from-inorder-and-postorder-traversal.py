# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        p = [len(postorder)-1]
        def traverse(l, r):
            if l>r:
                return None
            i = l
            while i<=r:
                if inorder[i] == postorder[p[0]]:
                    break
                i+=1
            node, p[0] = TreeNode(inorder[i]), p[0]-1
            node.right, node.left = traverse(i+1, r), traverse(l, i-1)
            return node
        return traverse(0,len(inorder)-1)