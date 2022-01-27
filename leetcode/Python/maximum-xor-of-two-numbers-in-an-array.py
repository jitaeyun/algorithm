class TRIE:
    def __init__(self):
        self.n = None
        self.v = list()
    def makeTrie(self):
        self.n = [TRIE(), TRIE()]
    def insertNode(self, bit, num, idx):
        r = self
        r.v.append(idx)
        while bit > 0:
            i = 1 if (bit&num)>0 else 0
            if r.n is None:
                r.makeTrie()
            r = r.n[i]
            r.v.append(idx)
            bit >>= 1
class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        def find_max_bit(num):
            bit = 1<<30
            while bit > 0:
                if (bit&num) > 0:
                    return bit
                bit >>= 1
            return 0
        sol, max_bit = 0, max(nums)
        t = TRIE()
        max_bit = find_max_bit(max_bit)
        for i in range(len(nums)):
            t.insertNode(max_bit, nums[i], i)
        for i in range(len(nums)):
            if nums[i] < max_bit:
                continue
            r, bit = t, max_bit
            while bit > 0:
                idx = 0 if (bit&nums[i])>0 else 1
                if len(r.n[idx].v) == 0:
                    r = r.n[idx^1]
                else:
                    r = r.n[idx]
                bit >>= 1
            sol = max(sol, nums[r.v[0]]^nums[i])
        return sol