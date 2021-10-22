class Solution:
    def frequencySort(self, s: str) -> str:
        v, sol, idx = [['0', 0] for _ in range(52)] , [], 0
        for ch in s:
            idx = ord(ch)-ord('a') if 'a'<=ch<='z' else ord(ch)-ord('A')+26
            v[idx][0], v[idx][1] = ch, v[idx][1]+1
        v.sort(key=lambda x: (-x[1],x[0]))
        for i in range(len(v)):
            for j in range(v[i][1]):
                sol.append(v[i][0])
        return ''.join(sol)