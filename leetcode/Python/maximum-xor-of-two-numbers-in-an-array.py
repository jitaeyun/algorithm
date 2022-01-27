class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        def initTrie():
            return {'next': None, 'count':0, 'val': 0}
        def makeTrie(trie, bit, num):
            t = trie;
            while bit > 0:
                i = 1 if (bit&num)>0 else 0
                if t.get('next', None) is None:
                    t['next'] = [initTrie(), initTrie()]
                t = t.get('next')[i]
                t['val'], t['count'] = num, t['count'] + 1
                bit >>= 1
        def find_max_bit(num):
            bit = 1<<30
            while bit > 0:
                if (bit&num) > 0:
                    return bit
                bit >>= 1
            return 1
        sol, max_bit, t = 0, max(nums), initTrie()
        max_bit = find_max_bit(max_bit)
        for num in nums:
            makeTrie(t, max_bit, num)
        for num in nums:
            if num < max_bit:
                continue
            r, bit = t, max_bit
            while bit > 0:
                idx = 0 if (bit&num)>0 else 1
                if r['next'][idx]['count'] == 0:
                    r = r['next'][idx^1]
                else:
                    r = r['next'][idx]
                bit >>= 1
            sol = max(sol, r.get('val')^num)
        return sol