class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        MAX_DUPLICATION = 2
        cnt, idx = 1, 0
        for i in range(1, len(nums)):
            if nums[idx] == nums[i]:
                if cnt < MAX_DUPLICATION:
                    idx = idx + 1
                    nums[idx] = nums[i]
                cnt += 1
            else:
                idx, cnt = idx + 1, 1
                nums[idx] = nums[i]
        return idx + 1
                    