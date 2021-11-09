class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        def makeMap(word):
            key = 0
            for ch in word:
                key|=(1<<(ord(ch)-ord('a')))
            um[key]=um.get(key,0)+1
        def traverse(v, num, n):
            if n==len(v):
                return um.get(num,0)
            return traverse(v, num|v[n], n+1) + traverse(v, num, n+1)
        def validWord(puzzle):
            key, v = 1<<(ord(puzzle[0])-ord('a')), list()
            basic, t = key, 0
            for i in range(1,len(puzzle)):
                t = 1<<(ord(puzzle[i])-ord('a'))
                if key == (key|t):
                    continue
                key|=t
                v.append(t)
            return traverse(v, basic, 0)
        sol, um = list(), dict()
        for word in words:
            makeMap(word)
        for puzzle in puzzles:
            sol.append(validWord(puzzle))
        return sol
        