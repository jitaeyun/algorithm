# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        sol = root
        d_node, p_node, s_node, sp_node, cur = None, None, None, None, root
        while cur:
            if cur.val == key:
                d_node = cur
                break
            elif cur.val < key:
                p_node, cur = cur, cur.right
            else:
                p_node, cur = cur, cur.left
        if d_node == None:
            return root
        if d_node.right and d_node.left:
            s_node, sp_node = d_node.right, d_node.right
            while s_node.left:
                sp_node, s_node = s_node, s_node.left
            if s_node!=sp_node:
                sp_node.left =  s_node.right
            else:
                d_node.right = s_node.right
            s_node.left, s_node.right = d_node.left, d_node.right
        elif d_node.left:
            s_node = d_node.left
        elif d_node.right:
            s_node = d_node.right
        if p_node == None:
            sol = s_node
        elif p_node.left == d_node:
            p_node.left = s_node
        else:
            p_node.right = s_node
        return sol
        