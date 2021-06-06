class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        m, sol = defaultdict(int), []
        for n in nums1:
            m[n]=1
        for n in nums2:
            if m[n] > 0:
                m[n]=0
                sol.append(n)
        return sol