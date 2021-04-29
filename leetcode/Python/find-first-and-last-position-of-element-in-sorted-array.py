class Solution:
    def __init__(self):
        self.sol = [-1,-1]
        self.nums = []
        self.target = 0

    def binarySearch(self, flag):
        l, r, m = 0, len(self.nums)-1, 0
        if len(self.nums) == 0:
            return
        while l<=r:
            m = (l+r)//2
            if self.nums[m] == self.target:
                self.sol[flag]=m
                if flag == 0:
                    r=m-1
                else:
                    l=m+1
            elif self.nums[m] < self.target:
                l=m+1
            else:
                r=m-1
        
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        self.nums, self.target = nums, target
        self.binarySearch(0)
        self.binarySearch(1)
        return self.sol