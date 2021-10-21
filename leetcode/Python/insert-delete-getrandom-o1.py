class RandomizedSet:

    def __init__(self):
        self.um = dict()
        self.v = list()
        self.idx = 0
    def insert(self, val: int) -> bool:
        if val in self.um:
            return False
        self.um[val]= len(self.v)
        self.v.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.um:
            return False
        idx = self.um[val]
        self.v[idx], self.um[self.v[-1]] = self.v[-1], idx
        self.v.pop()
        del self.um[val]
        return True

    def getRandom(self) -> int:
        return random.choice(self.v)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()