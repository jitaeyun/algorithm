class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        idx = -1
        for i in range(len(nums)-1, -1, -1):
            for j in range(i+1, len(nums)):
                if nums[i]<nums[j]:
                    if idx == -1 or nums[idx]>nums[j]:
                        idx = j
            if idx > -1:
                nums[i], nums[idx] = nums[idx], nums[i]
                idx = i
                break
        for i in range(idx + 1, len(nums)):
            t = i
            for j in range(i+1, len(nums)):
                if nums[t] > nums[j]:
                    t = j
            nums[i], nums[t] = nums[t], nums[i]
        