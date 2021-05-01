class WordFilter:
    def __init__(self, words: List[str]):
        self.m = {}
        for i,s in enumerate(words):
            for j in range(len(s)):
                for k in range(len(s)):
                    self.m[s[0:j+1]+'-'+s[-k:]]=i

    def f(self, prefix: str, suffix: str) -> int:
        sol = self.m.get(prefix+'-'+suffix)
        if sol is None:
            return -1
        return sol

# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)