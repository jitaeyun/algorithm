class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        um, sol, sz = defaultdict(int), 0, len(nums1)
        for i in range(sz):
            for j in range(sz):
                um[nums1[i]+nums2[j]]+=1
        for i in range(sz):
            for j in range(sz):
                val = nums3[i]+nums4[j]
                sol+=um[-val]
        return sol