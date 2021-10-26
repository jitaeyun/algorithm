# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        def _dfs(n):
            if not n:
                return
            n.left, n.right = n.right, n.left
            _dfs(n.left)
            _dfs(n.right)
        _dfs(root)
        return root


'''
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        cur, dq = None, collections.deque()
        if not root:
            return root
        dq.append(root)
        while dq:
            cur = dq.popleft()
            cur.left, cur.right = cur.right, cur.left
            if cur.left:
                dq.append(cur.left)
            if cur.right:
                dq.append(cur.right)
        return root
            
'''