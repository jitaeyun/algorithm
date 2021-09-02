# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        visit = [0]*(n+1)
        def traverse(l, r):
            res = []
            if l>r:
                return [None]
            for i in range(l,r+1):
                if visit[i]==1:
                    continue
                visit[i]=1
                for j in traverse(l,i-1):
                    for k in traverse(i+1,r):
                        res.append(TreeNode(i,j,k))
                visit[i]=0
            return res
        return traverse(1,n)