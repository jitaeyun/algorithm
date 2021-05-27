# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def __init__(self):
        self.t, self.s = None, None
    def serialize(self, root):
        s, dq = [], collections.deque()
        if not root:
            return s
        dq.append(root)
        while dq:
            t=dq.popleft()
            if not t:
                s.append(',n')
                continue
            s.append(',{}'.format(t.val))
            dq.append(t.left)
            dq.append(t.right)
        return ''.join(s)[1:]

    def deserialize(self, data):
        state, sol, dq = 0, TreeNode(0), collections.deque()
        if not data:
            return None
        for s in data.split(','):
            if len(dq)==0:
                sol.val=int(s)
                dq.append(sol)
                continue
            elif s != 'n':
                if state == 0:
                    dq[0].left=TreeNode(int(s))
                    dq.append(dq[0].left)
                else:
                    dq[0].right=TreeNode(int(s))
                    dq.append(dq[0].right)
            if state==1:
                dq.popleft()
            state=(state+1)%2
        return sol
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))