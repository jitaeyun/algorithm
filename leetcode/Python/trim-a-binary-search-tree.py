# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
        dq, c, p = collections.deque(), None, None
        sol = TreeNode(-1)
        sol.right = root
        dq.append([root, sol])
        while dq:
            c, p = dq.popleft()
            if c is None:
                continue
            elif c.val<low:
                if p.left == c:
                    p.left = c.right
                else:
                    p.right = c.right
                dq.append([c.right, p])
            elif c.val>high:
                if p.left == c:
                    p.left = c.left
                else:
                    p.right = c.left
                dq.append([c.left, p])
            else:
                dq.append([c.left, c])
                dq.append([c.right, c])
        return sol.right