class Solution:
    def __init__(self):
        self.v = []
        self.next = None
    def insert(self, i, word):
        cur, idx = self, 0
        for ch in word:
            idx = ord(ch)-ord('a')
            if cur.next is None:
                cur.next = [Solution() for i in range(26)]
            cur.next[idx].v.append(i)
            cur=cur.next[idx]
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        sol,idx,cur,sz = [], 0, self, 0
        products.sort()
        for i, v in enumerate(products):
            self.insert(i, v)
        for ch in searchWord:
            m = []
            idx = ord(ch)-ord('a')
            if cur.next is None:
                sol.append(m)
                continue
            cur=cur.next[idx]
            for i in range(min(3, len(cur.v))):
                m.append(products[cur.v[i]])
            sol.append(m)
        return sol