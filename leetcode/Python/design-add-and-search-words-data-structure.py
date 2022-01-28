class WordDictionary:

    def __init__(self):
        self.trie = dict()

    def initTrie(self):
        return {'count':0}

    def makeTrie(self, s):
        t = self.trie
        for ch in s:
            if t.get(ch) is None:
                t[ch] = self.initTrie()
            t = t.get(ch)
        t['count']+=1

    def addWord(self, word: str) -> None:
        self.makeTrie(word)

    def search(self, word: str) -> bool:
        return self.traverseSearch(self.trie, word, 0)

    def traverseSearch(self, trie, word, idx):
        t = trie
        for i in range(idx, len(word)):
            if t is None:
                return False
            elif word[i] == '.':
                for k, v in t.items():
                    if k == 'count':
                        continue
                    if self.traverseSearch(v, word, i+1):
                        return True
                return False
            elif t.get(word[i]) is None:
                return False
            t = t.get(word[i])
        return t.get('count',0) > 0

# Your WordDictionary object will be instantiated and called as such:

# obj = WordDictionary()

# obj.addWord(word)

# param_2 = obj.search(word)