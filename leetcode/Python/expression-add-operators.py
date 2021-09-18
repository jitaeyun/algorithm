class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        def addOperation(idx):
            if idx==0:
                dp[idx].append(num[idx])
                output[idx].append(int(num[idx]))
                prev[idx].append(int(num[idx]))
                last_num[idx].append(int(num[idx]))
                last_op[idx].append(0)
                return
            for i in range(len(dp[idx-1])):
                o = output[idx-1][i]
                p = prev[idx-1][i]
                ln = last_num[idx-1][i]
                lo = last_op[idx-1][i]
                # 1. +
                dp[idx].append('{}+{}'.format(dp[idx-1][i],num[idx]))
                prev[idx].append(int(num[idx]))
                output[idx].append(o+int(num[idx]))
                last_num[idx].append(int(num[idx]))
                last_op[idx].append(0)
                # 2. -
                dp[idx].append('{}-{}'.format(dp[idx-1][i],num[idx]))
                prev[idx].append(-int(num[idx]))
                output[idx].append(o-int(num[idx]))
                last_num[idx].append(int(num[idx]))
                last_op[idx].append(1)
                # 3. *
                dp[idx].append('{}*{}'.format(dp[idx-1][i],num[idx]))
                prev[idx].append(p*int(num[idx]))
                output[idx].append(o+prev[idx][-1]-p)
                last_num[idx].append(int(num[idx]))
                last_op[idx].append(2)
                if ln == 0:
                    continue
                # 4. 붙이기
                dp[idx].append('{}{}'.format(dp[idx-1][i],num[idx]))
                last_num[idx].append(ln*10+int(num[idx]))
                last_op[idx].append(lo)
                # 4.1 op가 +
                if lo == 0:
                    prev[idx].append(p*10+int(num[idx]))
                # 4.2 op가 -
                elif lo == 1:
                    prev[idx].append(p*10-int(num[idx]))
                # 4.3 op가 *
                else:
                    prev[idx].append((p//ln)*(10*ln+int(num[idx])))
                output[idx].append(o+prev[idx][-1]-p)
                
        dp, output, prev = [list() for _ in range(10)], [list() for _ in range(10)], [list() for _ in range(10)]
        last_num, last_op = [list() for _ in range(10)], [list() for _ in range(10)]
        sol = list()
        for i in range(len(num)):
            addOperation(i)
        for i in range(len(dp[len(num)-1])):
            if output[len(num)-1][i] == target:
                sol.append(dp[len(num)-1][i])
        return sol