class Node:
    def __init__(self):
        self.n = 0
        self.next = dict()

class MapSum:

    def __init__(self):
        self.node = dict()
        self.map = defaultdict(int)

    def insert(self, key: str, val: int) -> None:
        diff, cur = val - self.map[key], self.node
        self.map[key] = val
        for k in key:
            if not k in cur:
                cur[k] = Node()
            cur[k].n+=diff
            cur=cur[k].next

    def sum(self, prefix: str) -> int:
        sol, cur = 0, self.node
        for k in prefix:
            if not k in cur:
                return 0
            sol = cur[k].n
            cur=cur[k].next
        return sol


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)

'''
class MapSum:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.um = defaultdict(int)
        self.um_str = defaultdict(int)

    def insert(self, key: str, val: int) -> None:
        diff = val - self.um_str[key]
        self.um_str[key]=val
        for i in range(len(key)):
            self.um[key[0:i+1]]+=diff

    def sum(self, prefix: str) -> int:
        return self.um[prefix]
'''