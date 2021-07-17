class Solution:
    def threeEqualParts(self, arr: List[int]) -> List[int]:
        ones, state, ary, t = 0, 0, [-1,-1,-1], 0
        l, r = 0, 0
        #1. 1 count
        for i in arr:
            if i==1:
                ones+=1
        if ones==0:
            return [0,len(arr)-1]
        elif ones%3>0:
            return [-1,-1]
        ones//=3
        #2. divide range
        for i, v in enumerate(arr):
            if v==1:
                t+=1
                if ary[state]==-1:
                    ary[state]=i
                if t==ones:
                    state, t = state + 1, 0
            if state>=3:
                break
        #3. range check
        if len(arr)-ary[2] > ary[1] or len(arr)-ary[2] > ary[2]-ary[1]:
            return [-1,-1]
        for i in range(0, len(arr)-ary[2]):
            if arr[ary[0]+i]!=arr[ary[2]+i] or arr[ary[1]+i] != arr[ary[2]+i]:
                return [-1,-1]
            l, r = ary[0]+i, ary[1]+i+1 
            l=ary[0]+i
        return [l,r]