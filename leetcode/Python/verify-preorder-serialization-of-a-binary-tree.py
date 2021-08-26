class Solution:
    def __init__(self):
        self.v = None
        self.idx = 0
    def isValidPreorder(self):
        check_size = True if self.idx==0 else False
        if self.idx >= len(self.v):
            return False
        elif self.v[self.idx]=='#':
            return False if check_size and self.idx+1<len(self.v) else True
        self.idx+=1
        if not self.isValidPreorder():
            return False
        self.idx+=1
        if not self.isValidPreorder():
            return False
        return not check_size or (check_size and self.idx+1==len(self.v))
    def isValidSerialization(self, preorder: str) -> bool:
        self.v = preorder.split(',')
        return self.isValidPreorder()