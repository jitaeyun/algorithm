class Solution:
    def brokenCalc(self, startValue: int, target: int) -> int:
        sol, cur = 0, target
        while cur > startValue:
            if cur & 1  > 0:
                cur, sol = cur + 1 , sol + 1
            cur, sol = cur // 2 , sol + 1
        sol += startValue - cur
        return sol