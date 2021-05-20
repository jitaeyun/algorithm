# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        sol, sz, cur, dq= [], 0, None, collections.deque()
        if root is None:
            return 
        dq.append(root)
        while dq:
            t, sz= [], len(dq)
            for _ in range(sz):
                cur=dq.popleft()
                t.append(cur.val)
                if cur.left:
                    dq.append(cur.left)
                if cur.right:
                    dq.append(cur.right)
            sol.append(t)
        return sol