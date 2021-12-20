class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        sol, mn = list(), arr[1]-arr[0]
        for i in range(2, len(arr)):
            mn = min(mn,arr[i]-arr[i-1])
        for i in range(1, len(arr)):
            if mn == arr[i]-arr[i-1]:
                sol.append([arr[i-1],arr[i]])
        return sol