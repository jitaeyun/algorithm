class Solution:
    def calculate(self, s: str) -> int:
        nums, i, j, t, op = list(), 0, 0, 0, 0
        while i < len(s):
            if s[i]==' ':
                pass
            elif s[i]=='+':
                op = 1
            elif s[i]=='-':
                op = 2
            elif s[i]=='*':
                op = 3
            elif s[i]=='/':
                op = 4
            else:
                j = i
                while i < len(s) and s[i]>='0' and s[i]<='9':
                    i+=1
                t = int(s[j:i])
                if op == 0 or op == 1:
                    nums.append(t)
                elif op == 2:
                    nums.append(-t)
                elif op == 3:
                    nums[-1] *= t
                else:
                    nums[-1] = int(nums[-1]/t)
                i-=1
            i+=1
        return sum(nums)
            