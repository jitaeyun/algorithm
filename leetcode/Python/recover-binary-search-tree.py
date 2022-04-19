# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        dq , v, idx  = collections.deque(), list(), 0
        def traverse(node):
            nonlocal idx
            if node is None:
                return
            traverse(node.left)
            node.val, idx = v[idx], idx + 1
            traverse(node.right)
        dq.append(root)
        while dq:
            cur = dq.popleft()
            v.append(cur.val)
            if cur.left:
                dq.append(cur.left)
            if cur.right:
                dq.append(cur.right)
        v.sort()
        traverse(root)
