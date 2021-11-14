class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.v, self.idx, self.s = list(), 0, list()
        self.traverse(characters, combinationLength, 0)
        
    def traverse(self, characters, combinationLength, length):
        if len(self.s) == combinationLength:
            self.v.append(''.join(self.s))
            return
        elif len(characters) <= length:
            return
        self.s.append(characters[length])
        self.traverse(characters, combinationLength, length+1)
        self.s.pop()
        self.traverse(characters, combinationLength, length+1)

    def next(self) -> str:
        self.idx+=1
        return self.v[self.idx-1]

    def hasNext(self) -> bool:
        return self.idx<len(self.v)


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()