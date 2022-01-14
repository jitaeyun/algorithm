class Solution:
    def myAtoi(self, s: str) -> int:
        sol, idx, state, minus = 0, 0, 0, 0
        INT_MAX = (1<<31)
        while idx<len(s):
            if s[idx]!=' ':
                break
            idx+=1
        while idx<len(s):
            if state == 0 and (s[idx]=='-' or s[idx]=='+'):
                minus = 1 if s[idx]=='-' else 0
            elif s[idx]>='0' and s[idx]<='9':
                sol = sol*10 + int(s[idx])
            else:
                break
            if minus == 1 and sol >= INT_MAX:
                return -INT_MAX
            elif minus == 0 and sol >= INT_MAX-1:
                return INT_MAX-1
            idx, state = idx + 1, state + 1
        return sol if minus==0 else -sol
