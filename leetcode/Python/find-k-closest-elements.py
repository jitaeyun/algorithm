class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        idx, l, r, m, a, b, v = 0, 0, len(arr)-1, 0, 0, 0, 1000000
        while l<=r:
            m=(l+r)//2
            if arr[m]<x:
                l=m+1
            elif arr[m]==x:
                idx=m
                break
            else:
                r=m-1
            a=abs(arr[m]-x)
            if a<v:
                idx, v = m, a
        l, r,k = idx-1, idx+1, k-1
        while k>0 and l>=0 and r<len(arr):
            a,b,k = abs(arr[l]-x), abs(arr[r]-x),k-1
            if a<=b:
                l-=1
            else:
                r+=1
        if k>0:
            if l>=0:
                l-=k
            else:
                r+=k
        return arr[l+1:r]