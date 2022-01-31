class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        sol = 0
        for account in accounts:
            sol = max(sol, sum(account))
        return sol