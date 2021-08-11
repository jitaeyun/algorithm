class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        um, t = defaultdict(int), 0
        arr.sort()
        for n in arr:
            um[n]+=1
        for n in arr:
            if um[n]==0:
                continue
            elif n<0 and n%2>0:
                return False
            t = 2*n if n>=0 else n//2
            if (n==t and um[n]<2) or (n!=t and um[t]==0):
                return False
            um[n]-=1
            um[t]-=1
        return True