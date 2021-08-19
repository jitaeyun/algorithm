# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.allSum = 0
        self.diff = 1000000007
        self.MOD = 1000000007
        self.a = 0
        self.b = 0
        self.t = 0
    def traverseSum(self, root):
        sol = 0
        q = collections.deque()
        q.append(root)
        while q:
            t = q.popleft()
            if t.left:
                q.append(t.left)
            if t.right:
                q.append(t.right)
            sol+=t.val
        return sol
    def findNum(self, node):
        if not node:
            return 0
        l=self.findNum(node.left)
        r=self.findNum(node.right)
        self.t=max(self.allSum-l,l)-min(self.allSum-l,l)
        if self.diff>self.t:
            self.diff, self.a, self.b = self.t, self.allSum-l, l
        self.t=max(self.allSum-r,r)-min(self.allSum-r,r)
        if self.diff>self.t:
            self.diff, self.a, self.b = self.t, self.allSum-r, r
        return l+r+node.val
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        self.allSum = self.traverseSum(root)
        self.findNum(root)
        sol = (self.a*self.b)%self.MOD
        return sol