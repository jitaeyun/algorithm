class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        def binarySearch(l, r):
            m = 0
            while l<=r:
                m = (l+r)//2
                if nums[m]<target:
                    l = m + 1
                elif nums[m]>target:
                    r = m - 1
                else:
                    return True
            return False
        base_idx = -1
        l, r = 0, len(nums)-1
        for i in range(1, len(nums)):
            if nums[i-1] > nums[i]:
                base_idx = i - 1
                break
        if base_idx >= 0 and nums[0]<=target<=nums[base_idx]:
            r = base_idx
        else:
            l = base_idx+1
        return binarySearch(l, r)
        