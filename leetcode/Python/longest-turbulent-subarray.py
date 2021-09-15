class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        sol, one, two = 1, 1, 1
        for i in range(1,len(arr)):
            if arr[i-1]==arr[i]:
                one=two=1
            elif i%2 == 0:
                if arr[i-1]>arr[i]:
                    one, two = one + 1, 1
                else:
                    one, two = 1, two + 1
            else:
                if arr[i-1]>arr[i]:
                    one, two = 1, two + 1
                else:
                    one, two = one + 1, 1
            sol = max(sol, one, two)
        return sol