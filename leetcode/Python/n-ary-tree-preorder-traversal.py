"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def __init__(self):
        self.list = []
        
    def dfs(self,node):
        if node is None:
            return
        self.list.append(node.val)
        for n in node.children:
            self.dfs(n)
            
    def preorder(self, root: 'Node'):
        self.dfs(root)
        return self.list