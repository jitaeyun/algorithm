class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        sol, um = [], defaultdict(int)
        nums = nums1 if len(nums1) > len(nums2) else nums2
        comps = nums2 if len(nums1) > len(nums2) else nums1
        for n in nums:
            um[n]+=1
        for n in comps:
            if um[n]>0:
                um[n]-=1
                sol.append(n)
        return sol