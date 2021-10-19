class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        sol, st, um = list(), list(), dict()
        for n in nums2:
            while st and st[-1]<n:
                um[st.pop()]=n
            st.append(n)
        while st:
            um[st.pop()]=-1
        for n in nums1:
            sol.append(um[n])
        return sol