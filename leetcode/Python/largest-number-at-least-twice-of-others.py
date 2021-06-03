class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        def to_swap(a, b):
            return str(a) + str(b) < str(b) + str(a)
        for i in range(len(nums)):
            idx = i
            for j in range(i+1,len(nums)):
                if to_swap(nums[idx], nums[j]):
                    idx=j
            nums[i], nums[idx] = nums[idx], nums[i]
        for i in range(len(nums)):
            nums[i]=str(nums[i])
        if nums[0] == '0':
            return '0'
        return ''.join(nums)