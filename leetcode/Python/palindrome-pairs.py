class TrieNode:
    def __init__(self):
        self.idx = -1
        self.us = []
        self.um = dict()
class Trie:
    def __init__(self):
        self.node = TrieNode()
    def palindrome(self, w):
        return w[::-1]==w
    def insert(self, idx, w):
        cur = self.node
        for i in range(len(w),0,-1):
            if self.palindrome(w[:i]):
                cur.us.append(idx)
            if w[i-1] not in cur.um:
                cur.um[w[i-1]]=TrieNode()
            cur=cur.um[w[i-1]]
        cur.idx=idx
    def search(self, idx, w, res):
        cur=self.node
        for i in range(len(w)):
            if cur.idx>=0:
                if self.palindrome(w[i:]):
                    res.append([idx, cur.idx])
            if w[i] not in cur.um:
                return
            cur=cur.um[w[i]]
        if cur.idx >= 0 and cur.idx != idx:
            res.append([idx, cur.idx])
        for t in cur.us:
            if t == idx:
                 continue
            res.append([idx, t])
class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        sol ,t = [], Trie()
        for i, w in enumerate(words):
            t.insert(i,w)
        for i, w in enumerate(words):
            t.search(i,w,sol)
        return sol
        