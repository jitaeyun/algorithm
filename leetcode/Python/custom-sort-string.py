class Solution:
    def customSortString(self, order: str, str: str) -> str:
        visit, sol = [0]*26, []
        for i in str:
            visit[ord(i)-ord('a')]+=1
        for i in order:
            for j in range(visit[ord(i)-ord('a')]):
                sol.append(i)
            visit[ord(i)-ord('a')] = 0
        for i in range(len(visit)):
            for j in range(visit[i]):
                sol.append(chr(ord('a')+i))
        return ''.join(sol)