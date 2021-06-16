class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        mn, n, mIdx, idx = 0, 1, 0, 1
        nums.sort()
        for i in range(1,len(nums)):
            if nums[i]==nums[i-1]:
                n+=1
                if n > mn:
                    mn, mIdx = n, idx
            else:
                n, idx = 1, i
        return nums[mIdx]