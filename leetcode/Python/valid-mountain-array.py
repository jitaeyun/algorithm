class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        inIdx, deIdx = 0, len(arr)-1
        while inIdx + 1 < len(arr):
            if arr[inIdx] >= arr[inIdx+1]:
                break
            inIdx += 1
        while deIdx >= 1:
            if arr[deIdx] >= arr[deIdx-1]:
                break
            deIdx -= 1
        return inIdx==deIdx and inIdx > 0 and inIdx+1 < len(arr)