# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        us, dq, node = set(), collections.deque(), None
        dq.append(root)
        while dq:
            node = dq.popleft()
            if (k-node.val) in us:
                return True
            us.add(node.val)
            if node.left:
                dq.append(node.left)
            if node.right:
                dq.append(node.right)
        return False