"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        dq, sol, node = collections.deque(), [], None
        dq.append(root)
        while dq:
            v = []
            for i in range(len(dq)):
                node = dq.popleft()
                if node is None:
                    continue
                v.append(node.val)
                for c in node.children:
                    dq.append(c)
            if v:
                sol.append(v[:])
        return sol