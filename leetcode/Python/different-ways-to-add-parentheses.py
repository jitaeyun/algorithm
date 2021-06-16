class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        dp, nums, ops = [[[] for j in range(10)] for i in range(10)], [] , []
        def _parsing():
            s = []
            for ch in expression:
                if ch>='0' and ch<='9':
                    s.append(ch)
                else:
                    nums.append(int(''.join(s)))
                    ops.append(ch)
                    s.clear()
            nums.append(int(''.join(s)))
        def _subCalculation(l, r):
            t=0
            if l==r:
                dp[l][r].append(nums[l])
            for i in range(l,r):
                for a in dp[l][i]:
                    for b in dp[i+1][r]:
                        if ops[i]=='+':
                            t=a+b
                        elif ops[i]=='-':
                            t=a-b
                        else:
                            t=a*b
                        dp[l][r].append(t)
        _parsing()
        for i in range(len(nums)):
            l, r = 0, i
            while r<len(nums):
                _subCalculation(l,r)
                l, r = l+1, r+1
        return dp[0][len(nums)-1]