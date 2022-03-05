class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        cs, cn, ps, pn, v = 0, 0, 0, 0, list()
        nums.sort()
        for i in range(len(nums)):
            if len(v) == 0 or v[-1][0] != nums[i]:
                v.append([nums[i], nums[i]])
            else:
                v[-1][1] += nums[i]
        for i in range(len(v)-1, -1, -1):
            cn, cs = max(ps, pn), pn + v[i][1]
            if i+1 < len(v) and v[i][0]+1<v[i+1][0]:
                cs = max(cs, ps+v[i][1])
            pn, ps = cn, cs
        return max(cs,cn)