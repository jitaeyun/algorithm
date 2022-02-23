"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return node
        info = [None]*101
        info[node.val] = Node(val=node.val)
        dq = collections.deque()
        dq.append(node)
        while len(dq) > 0:
            ori = dq.popleft()
            for n in ori.neighbors:
                if info[n.val] is None:
                    info[n.val] = Node(n.val)
                    dq.append(n)
                info[ori.val].neighbors.append(info[n.val])
        return info[node.val]
        