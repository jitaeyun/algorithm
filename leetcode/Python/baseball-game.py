class Solution:
    def calPoints(self, ops: List[str]) -> int:
        v = list()
        for op in ops:
            if op == '+':
                v.append(v[-1]+v[-2])
            elif op == 'D':
                v.append(v[-1]*2)
            elif op == 'C':
                v.pop()
            else:
                v.append(int(op))
        return sum(v)