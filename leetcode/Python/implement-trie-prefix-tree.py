class Trie:

    def __init__(self):
        self.count, self.end = 0, 0
        self.next = None

    def makeTrie(self):
        return [Trie() for i in range(26)]
        
    def insert(self, word: str) -> None:
        self.count+=1
        t, idx = self, 0
        for i in word:
            idx=ord(i)-ord('a')
            if not t.next:
                t.next = self.makeTrie()
            t.next[idx].count+=1
            t=t.next[idx]
        t.end+=1
        
    def search(self, word: str) -> bool:
        t, idx = self, 0
        for i in word:
            idx=ord(i)-ord('a')
            if not t.next or t.next[idx].count == 0:
                return False
            t=t.next[idx]
        return t.end>0
        
    def startsWith(self, prefix: str) -> bool:
        t, idx = self, 0
        for i in prefix:
            idx=ord(i)-ord('a')
            if not t.next or t.next[idx].count == 0:
                return False
            t=t.next[idx]
        return True
        
# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)