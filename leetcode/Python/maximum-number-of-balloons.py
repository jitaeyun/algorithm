class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        sol, um = 100000, defaultdict(int)
        for c in text:
            um[c]+=1
        for c in 'balon':
            if c=='l' or c=='o':
                sol=min(sol,um[c]//2)
            else:
                sol=min(sol,um[c])
        return sol