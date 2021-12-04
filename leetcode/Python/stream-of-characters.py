class TRIE:
    def __init__(self):
        self.w, self.t = 0, [None]*26
    def addNode(self, ch):
        idx = ord(ch) - ord('a')
        if self.t[idx] == None:
            self.t[idx] = TRIE()
        return self.t[idx]
    def nextNode(self, ch):
        idx = ord(ch) - ord('a')
        return self.t[idx]
    def addWord(self):
        self.w+=1
    def isWord(self):
        return self.w>0
class StreamChecker:
    def __init__(self, words: List[str]):
        self.trie, self.letters = TRIE(), list()
        for word in words:
            cur = self.trie
            for i in range(len(word)-1, -1, -1):
                cur = cur.addNode(word[i])
            cur.addWord()
    def query(self, letter: str) -> bool:
        cur = self.trie
        self.letters.append(letter)
        for i in range(len(self.letters)-1, -1, -1):
            cur = cur.nextNode(self.letters[i])
            if cur is None:
                return False
            elif cur.isWord():
                return True
        return cur.isWord()


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)