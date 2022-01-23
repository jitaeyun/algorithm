class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        def makeInitNum(len):
            num = ''
            for i in range(len):
                num += str(i+1)
            return int(num)
        def makeSumNum(len):
            num = ''
            for i in range(len):
                num += '1'
            return int(num)
        sol = list()
        mn, mx = len(str(low)), len(str(high))
        for i in range(mn, min(mx+1, 10)):
            n = makeInitNum(i)
            p = makeSumNum(i)
            for j in range(i, 10):
                if n>=low and n<=high:
                    sol.append(n)
                n += p
        return sol