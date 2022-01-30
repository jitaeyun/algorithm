class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        sz, sol = len(nums), list()
        s = sz - (k%sz)
        for i in range(s, sz):
            sol.append(nums[i])
        for i in range(s):
            sol.append(nums[i])
        nums[:] = sol
        