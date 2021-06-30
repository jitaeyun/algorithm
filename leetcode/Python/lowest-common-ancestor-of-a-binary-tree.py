# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        l, r = [], []
        def _findAncestor(node, v, val):
            if node is None:
                return
            v.append(node)
            if v[-1].val==val:
                return
            _findAncestor(node.left,v,val)
            if v[-1].val==val:
                return
            _findAncestor(node.right,v,val)
            if v[-1].val==val:
                return
            v.pop()
        _findAncestor(root,l,p.val)
        _findAncestor(root,r,q.val)
        while len(l) < len(r):
            r.pop()
        while len(l) > len(r):
            l.pop()
        while l[-1].val != r[-1].val:
            l.pop()
            r.pop()
        return l[-1]

'''
# anosolution
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root is None:
            return root
        if root.val == p.val or root.val == q.val:
            return root
        l = self.lowestCommonAncestor(root.left,p,q)
        r = self.lowestCommonAncestor(root.right,p,q)
        if l is None:
            return r
        elif r is None:
            return l
        return root
'''