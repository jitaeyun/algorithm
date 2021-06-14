class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        sol = 0
        for k,v in sorted(boxTypes, key=lambda x: -x[1]):
            if truckSize>=k:
                truckSize-=k
                sol += k*v
            else:
                sol += truckSize*v
                break
        return sol