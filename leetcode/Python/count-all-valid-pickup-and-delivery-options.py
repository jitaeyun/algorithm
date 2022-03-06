class Solution:
    def countOrders(self, n: int) -> int:
        sol = 1
        for i in range(n*2, 1, -2):
            sol *= ((i)*(i-1))//2
            sol %= 1000000007
        return sol